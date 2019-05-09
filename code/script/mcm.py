# encoding=utf-8
import pytesseract
import os
import sys
import time
import xlsxwriter
import urllib
import socket
import threading
from urllib import request
from PIL import Image
from wand.image import Image as ImageWand


URL_PRE = 'http://www.comap-math.com/mcm/2019Certs/'  # URL前缀
# WORK_ROOT = '/Users/fanhongyu/data/'  # 工作根路径
WORK_ROOT = '/root/mcm/'  # 工作根路径 server
# 最小队伍号
# MIN_TEAM = 1900002
# MIN_TEAM = 1900562
MIN_TEAM = 1901595
MAX_TEAM = 1926758  # 最大队伍号
COUNT_PRE_XLS = 1000  # 每张表格队伍数量
COUNT_THREAD = 5  # 线程数量
# 设置超时时间为40s
socket.setdefaulttimeout(40)


def convert_pdf_to_jpg(pdfPath, imagePath):
    with ImageWand(filename=pdfPath) as img:
        with img.convert('jpeg') as converted:
            converted.save(filename=imagePath)


def jpg_to_string(imagePath):
    return pytesseract.image_to_string(Image.open(imagePath))


def delete_file(path):
    if os.path.exists(path):
        os.remove(path)


fliter_key = ['Harbin', 'Nanjing', 'Beijing', 'Finance', 'South',
              'Tianjin', 'Peking', 'Hebei', 'Shenzhen', 'Dalian',
              'Zhejiang', 'Jinan', 'Jilin', 'Shanghai', 'Wuhan',
              'Business', 'Polytechnical']


def notMySchool(school):
    for key in fliter_key:
        if key in school:
            return True
    return False


def needPrint(team_info):
    if ('Successful' in team_info):
        print('Successful')
        return False
    if ('Honorable' in team_info):
        print('Honorable')
        return False
    if ('Disq' in team_info):
        print('Disq')
        return False
    if ('Meritorious' in team_info) and notMySchool(team_info):
        print('other shcool Meritorious')
        return False
    return True


def get_team_info(num):
    number = str(num)
    begin_time = time.time()
    print('<==============Team ' + number + ' start ==============>')
    # 通过队伍号构建url和地址
    pdf_url = URL_PRE + number + '.pdf'
    pdf_path = WORK_ROOT + number + '.pdf'
    img_path = WORK_ROOT + number + '.jpeg'
    # 将pdf文件下载到本地
    try:
        request.urlretrieve(pdf_url, pdf_path)
        print('download success')
    except socket.timeout:
        # 下载超时
        print('download timeout')
        return 'error'
    except Exception as e:
        # 这里有可能会404
        print('download failed')
        return 'error'
    # 将pdf转化为jpeg格式的图片
    convert_pdf_to_jpg(pdf_path, img_path)
    # 从图片中提取文字
    team_info = jpg_to_string(img_path)
    # 不打印s、h奖了。。。
    if(needPrint(team_info)):
        print(team_info)
    # 删除中间生成的文件
    delete_file(pdf_path)
    delete_file(img_path)
    total_time = int(time.time() - begin_time)
    print('### Team ' + number + ' end  totalTime: ' + str(total_time) + 's')
    return team_info


def build_excel(begin_num, end_num):
    # 新建xls表格
    xls_path = WORK_ROOT + str(begin_num) + '~' + str(end_num) + '.xlsx'
    excel = xlsxwriter.Workbook(xls_path)
    sheet1 = excel.add_worksheet()
    # 填写第一行
    # sheet1.write(0, 0, '队伍号')
    # sheet1.write(0, 1, '姓名')
    # sheet1.write(0, 2, '学校')
    # sheet1.write(0, 3, '奖项')
    for team_num in range(begin_num, end_num):
        # 超出最大上限直接跳出
        if team_num > MAX_TEAM:
            break
        team_info = get_team_info(team_num)
        # 错误处理
        if 'error' == team_info:
            continue
        team_info = str(team_num) + '\n' + team_info
        team_info = team_info.split('\n')
        line = team_num - begin_num + 1
        for j in range(0, len(team_info)):
            sheet1.write(line, j, team_info[j])
    # 保存文件
    excel.close()


# 从out文件中读取
def count_out(path):
    res = 0
    f = open(path)               
    line = f.readline()
    while line:
        if 'Qinh' in line:
            res += 1
    f.close()
    return res


# 后台运行脚本 nohup python3 -u mcm.py > log.out 2>&1 &
# 确认脚本是否还在运行 ps -ef | grep python3
# 监控输出文件tail -f log.out
if __name__ == '__main__':
    threads = []
    for i in range(0, COUNT_THREAD):
        start = MIN_TEAM + COUNT_PRE_XLS * i
        end = start + COUNT_PRE_XLS
        t = threading.Thread(target=build_excel(start, end))
        threads.append(t)
    # 遍历构造好的线程
    for t in threads:
        t.setDaemon(True)
        t.start()
    t.join()
    print ('ok ok ok ok ok ok ok ok ok ok ok ok ok ')

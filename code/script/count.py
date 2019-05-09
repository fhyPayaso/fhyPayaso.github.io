# encoding=utf-8
import xlrd


if __name__ == '__main__':
    # 打开文件
    workbook = xlrd.open_workbook('')
    sheet = workbook.sheet_by_index(0)
    for i in range(0, sheet.nrows):
        if 'Qinhuang' in sheet.row(i)[1].value.encode('utf-8'):
            


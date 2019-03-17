# -*- coding: utf-8 -*-
import sys
import os
import time
from qiniu import Auth, put_file, etag

"""
基于mac自带的pyhton2.7

1. 没环境的安装pip

    sudo easy_install pip
    
2. 官方文档

    https://developer.qiniu.com/kodo/sdk/1242/python

"""

# 初始化信息
img_path = sys.argv[1]
img_base_url = 'http://img.hellofhy.cn/'
bucket_name = 'picture'
access_key = 'V4bRlWyjq34V1c2WVvd39rm4WR7qAcaTtQ0Zs7rL'
secret_key = 'ot-QQmfoY_Cnnn9FZ2B2_-nNuakOIuQubvFOe1-J'

# 构建图片名称
current_time_millis = time.time()
current_format_time = time.strftime('%Y.%m.%d', time.localtime(current_time_millis))
img_name = current_format_time + '/' + bytes(current_time_millis) + '.png' 

#构建鉴权对象
q = Auth(access_key, secret_key)
#生成上传 Token，可以指定过期时间等
token = q.upload_token(bucket_name, img_name, 3600)
# 开始上传
ret, info = put_file(token, img_name, img_path)
# 判断是否上传成功
if ret['key'] == img_name and ret['hash'] == etag(img_path):
    img_url = img_base_url + img_name
    print img_url
    print '![](' + img_url + ')'
else:
    print(info)




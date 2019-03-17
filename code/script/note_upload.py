# -*- coding: utf-8 -*-
# 平时在公司和家切换时候用
import os
print("<============= upload begin ==============>")
os.system('git add .')
os.system('git commit -m "Transfer location or something"')
os.system('git push origin hexo')
print("<============= upload success ==============>")
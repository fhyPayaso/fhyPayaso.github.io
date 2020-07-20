#!/usr/bin/env python
# -*- coding: utf-8 -*-


path = '/Users/fanhongyu/workspace/fhyPayaso.github.io/code/Algorithm/leetcode/'

import os



ls = os.listdir(path)
count = 0
for i in ls:
    if os.path.isfile(os.path.join(path,i)):
        count += 1
print count



"""

人们普遍认为  It is commonly believed that…
我同意前者(后者)观点  I give my vote to the former/latter opinion.
不可否认  It is undeniable that…
就我而言/ 就个人而言  As far as I am concerned,/Personally,
利远远大于弊 The advantages far outweigh the disadvantages.
考虑到诸多因素  take many factors into consideration
从另一个角度  from another perspective
应当承认 Admittedly
社会进步的体现 a symbol of society progress
大大方便了人们的生活  Sth has greatly facilitated people's lives
导致很多问题 give rise to/lead to/spell various problems
"""

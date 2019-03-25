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
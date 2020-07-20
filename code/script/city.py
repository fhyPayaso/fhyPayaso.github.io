#!/usr/bin/env python
# -*- coding: utf-8 -*-
from functools import cmp_to_key


class City:
    def __init__(self, name):
        self.name = name
        self.times = 0
        self.rank = []
        self.avg = 0.0

    def update(self):
        all_rank = 0
        for r in self.rank:
            all_rank += r
        self.avg = all_rank / self.times


city_list_four_year = [
    ["成都", "杭州", "武汉", "天津", "南京",  "重庆", "西安",
     "长沙", "青岛",  "沈阳", "大连", "厦门", "苏州", "宁波", "无锡"],  # 2016
    ["成都", "杭州", "武汉", "重庆", "南京",  "天津", "苏州",
     "西安", "长沙",  "沈阳", "青岛", "郑州", "大连", "东莞", "宁波"],  # 2017
    ["成都", "杭州", "重庆", "武汉", "苏州", "西安",  "天津",
     "南京", "郑州", "长沙",  "沈阳", "青岛", "宁波", "东莞", "无锡"],  # 2018
    ["成都", "杭州", "重庆", "武汉", "西安", "苏州", "天津",
     "南京", "长沙", "郑州", "东莞", "青岛", "沈阳", "宁波", "昆明"]  # 2019
]

city_list = []


def gen_data():
    for city_per_year in city_list_four_year:
        for i in range(1, len(city_per_year)+1):
            city_name = city_per_year[i-1]
            item = [it for it in city_list if it.name == city_name]
            if(len(item) == 0):
                city_list.append(City(city_name))
            for it in city_list:
                if it.name == city_name:
                    it.times += 1
                    it.rank.append(i)


def mycmp(x, y):
    if x.times == y.times:
        return x.avg-y.avg
    return -(x.times-y.times)


if __name__ == "__main__":
    gen_data()
    for city in city_list:
        city.update()
    city_list.sort(key=cmp_to_key(mycmp))
    id = 0
    for city in city_list:
        id += 1
        print("{}: {}  上榜次数: {}  平均排名: {}".format(
            id, city.name, city.times, city.avg
        ))
    pass

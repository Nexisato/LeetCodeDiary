'''
Date: 2024-02-25 21:58:14
Author: nexisato
FilePath: /LeetCodeDiary/TestRepo/24-02-25/rand9.py
Description: 根据两个rand7()，进制转换，实现rand9()
'''
#-*- coding: utf-8 -*-
import random

def rand7():
    return random.randint(1, 7)

def rand9():
    while True:
        r1 = rand7()
        r2 = rand7()
        num = (r1 - 1) * 7 + r2
        if num <= 9:
            return num
        
if __name__ == '__main__':
    table = dict()
    for _ in range(0, 10000):
        num = rand9()
        table[num] = table.get(num, 0) + 1
    for i in range(1, 10):
        print(i, table[i])
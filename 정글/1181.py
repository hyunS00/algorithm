import sys
from functools import cmp_to_key

def cmp(a,b):
    if len(a) < len(b):
        return 1
    elif len(a) == len(b):
        

N = int(input())

word_list = [sys.stdin.readline() for i in range(N)]

print(word_list)

sorted_list = sorted(word_list, key=cmp_to_key(cmp))

print(sorted_list)
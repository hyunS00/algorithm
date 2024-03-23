import sys
from functools import cmp_to_key

def cmp(a,b):
    if len(a) < len(b):
        return -1
    elif len(a) == len(b):
        if a < b:
            return -1
        else :
            return 1
    else:
        return 1
    
    
        

N = int(input())

word_list = [sys.stdin.readline() for i in range(N)]

set_list = set(word_list)

sorted_list = sorted(set_list, key=cmp_to_key(cmp))

for word in sorted_list:
    print(word[:-1])
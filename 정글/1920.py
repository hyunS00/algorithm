import sys

def binary_search(list,target,start,end):
    mid = int((end + start)/2)
    if mid > end or mid < start:
        return 0
    
    if list[mid] == target:
        return 1
    
    if list[mid] > target:
        return binary_search(list,target,start,mid-1)
    else:
        return binary_search(list,target,mid+1,end)
        

N = int(input())

A = list(map(int,sys.stdin.readline().split()))

M = int(input())

B = list(map(int,sys.stdin.readline().split()))

A.sort()

for i in range(M):
    print(binary_search(A,B[i],0,int(len(A))-1))
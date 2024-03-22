import sys

def is_prime(num):
    
    if num == 1:
        return False
    
    for i in range(2, num):
        if num % i == 0:
            return False
        
    return True

N = int(input())
nums = list(map(int,sys.stdin.readline().split()))

cnt = 0
for num in nums:
    if(is_prime(num)):
        cnt += 1
print(cnt)
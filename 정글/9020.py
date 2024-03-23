import sys
import bisect

def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return True
        elif arr[mid] > target:
            end = mid -1
        else:
            start = mid + 1


T = int(input())

nums = [int(sys.stdin.readline()) for i in range(T)]
primes = [2,3]

for i in range(3,10000,2):
    seq = 1
    while primes[seq] * primes[seq] <= i:
        if i % primes[seq] == 0:
            break
        seq += 1

    else: primes.append(i)

for num in nums:

    left = num / 2
    right = num / 2
    for i in range(int(num/2)):
        if binary_search(primes,left,0,len(primes)) and binary_search(primes,right,0,len(primes)):
            print(f'{int(left)} {int(right)}')
            break
    
        left -= 1
        right += 1
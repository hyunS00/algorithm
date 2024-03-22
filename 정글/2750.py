import sys

N = int(input())

nums = [int(sys.stdin.readline()) for i in range(N)]

sort_nums = sorted(nums)

for num in sort_nums:
    print(num)
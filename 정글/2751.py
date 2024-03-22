import sys

N = int(input())

nums = [int(sys.stdin.readline()) for i in range(N)]

sort_nums = sorted(nums,reverse=False)

for i in range(N):
    print(sort_nums[i])
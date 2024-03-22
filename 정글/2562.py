import sys

nums = list(int(sys.stdin.readline()) for i in range(9))

max_idx = 0
for i in range(1,9):
    if nums[max_idx] < nums[i]:
        max_idx = i

print(nums[max_idx])
print(max_idx+1)
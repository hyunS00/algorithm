import sys

line = sys.stdin.readline().rstrip().split('-')

for idx, nums in enumerate(line):
    if len(nums) <= 1:
        line[idx] = int(nums)
        continue

    split_nums = nums.split('+')
    sum = 0
    for num in split_nums:
        sum += int(num)
    line[idx] = sum

minus_sum = line[0]

for i in range(1, len(line)):
    minus_sum -= line[i]

print(minus_sum)
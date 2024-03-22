def solve(a):
    sum = 0
    for num in a:
        sum += num
    return sum


input_list = list({1,2,3,4,5})
print(solve(input_list))
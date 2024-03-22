import sys

T = int(input())

testcase_list = [list(sys.stdin.readline().split()) for i  in range(T)]

for testcase in testcase_list:
    R = int(testcase[0])
    S = testcase[1]

    answer = ""
    for string in S:
        answer += string * R
    print(answer)
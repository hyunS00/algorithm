import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())

    grade = []
    for _ in range(N):
        a, b = map(int,input().split())
        grade.append((b, a))
    
    grade.sort()

    lower_socre = float('inf')
    cnt = 0
    for second, first in grade:
        if first <= lower_socre:
            lower_socre = first
            cnt += 1
    print(cnt)


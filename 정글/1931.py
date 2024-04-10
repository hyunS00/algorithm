import sys
input = sys.stdin.readline

N = int(input())
resolvation = []

for _ in range(N):
    start, end = map(int,input().split())
    resolvation.append((start, end))

endpoint = 0
cnt = 0

resolvation.sort(key=lambda x:(x[1], x[0]))

for start, end in resolvation:
    if endpoint <= start:
        endpoint = end
        cnt += 1

print(cnt)
import sys

N, K = map(int, sys.stdin.readline().split())
A = [0] * N

for i in range(N):
    coin = int(sys.stdin.readline())
    A[i] = coin

coin_cnt = 0
for i in range(len(A)-1, -1, -1):
    if A[i] <= K:
        coin_cnt += K // A[i]
        K %= A[i]

print(coin_cnt)
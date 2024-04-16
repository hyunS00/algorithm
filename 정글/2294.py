import sys
input = sys.stdin.readline

n, k = map(int, input().split())

coin = []

for _ in range(n):
    coin.append(int(input()))

inf = float('inf')

dp = [[inf] * (k+1) for _ in range(n+1)]

for i in range(n+1):
    dp[i][0] = 0

for i in range(1,n+1):
    for j in range(1,k+1):
        if j < coin[i-1]:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = min(dp[i][j-coin[i-1]]+1, dp[i-1][j])

if dp[n][k] == inf:
    print(-1)
else:
    print(dp[n][k])
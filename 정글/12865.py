import sys
input = sys.stdin.readline

def bottom_up(N,K):
    global W, V
    for i in range(1,N+1):  # 아이템
        for j in range(1,K+1): # 배낭무게 하나씩 늘리기
            if W[i] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+V[i])

N, K = map(int, input().split())

V = [0] * (N+1)
W = [0] * (N+1)
dp = [[0]*(K+1) for _ in range(N+1)]

for i in range(1, N+1):
    w, v = map(int, input().split())

    if w > K:
        continue
    V[i] = v
    W[i] = w

bottom_up(N,K)
print(dp[N][K])
import sys
input = sys.stdin.readline

def bottom_up(N, M, dp):
    for i in range(1, N + 1):
        dp[i][0] = 1
        for j in range(1, M + 1):
            if coin[i] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]]
            # print(f'i:{i} j:{j} dp:{dp}')
    return dp[N][M]

T = int(input())

for _ in range(T):
    N = int(input())
    coin = list(map(int, input().split()))
    coin = [0] + coin
    M = int(input())

    dp = [[0] * (M+1) for _ in range(N+1)]

    print(bottom_up(N, M, dp))
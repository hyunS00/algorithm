import sys
input = sys.stdin.readline

def bottom_up(N):
    global INF,dp
    for x in range(4,N+1):
        a, b, c = INF, INF, INF
        if x % 2 == 0:
            a = dp[x//2] + 1

        if x % 3 == 0:
            b = dp[x//3] + 1
        
        c = dp[x-1] + 1
        dp[x] = min(a, b, c)

    return dp[N]
    

N = int(input())
INF = float('inf')

dp = [INF] * 1000001
dp[2] = 1
dp[3] = 1

print(bottom_up(N))
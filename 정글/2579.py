import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def bottom_up(n,dp):
    global stair

    for i in range(2,n+1):
        dp[i] = max(dp[i-2], stair[i-1]+ dp[i-3]) + stair[i]
    return dp[n]

N = int(input())
stair = [0] * (N + 1)
dp = [0] * (N + 1)

for i in range(1, N+1):
    floor = int(input())
    stair[i] = floor

dp[1] = stair[1]

print(bottom_up(N,dp))
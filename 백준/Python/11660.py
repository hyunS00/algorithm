import sys
input = sys.stdin.readline

N, M = map(int, input().split())

board = [[0]*(N+1)]
dp = [[0]*(N+1) for _ in range(N+1)]

for i in range(N):
    line = [0] + list(map(int, input().split()))
    board.append(line)

for y in range(1, N+1):
    for x in range(1, N+1):
        dp[x][y] = dp[x-1][y] + dp[x][y-1] - dp[x-1][y-1] + board[x][y]

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())

    ans = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]
    print(ans)
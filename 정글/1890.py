import sys
input = sys.stdin.readline

def bottom_up(N, board, dp):
    

    for x in range(N):
        for y in range(N):
            if x == N-1 and y == N-1:
                return dp[N-1][N-1]

            if not dp[x][y]:
                continue
            
            for dx, dy in move:
                lx = x + (dx * board[x][y])
                ly = y + (dy * board[x][y])

                if lx >= N or ly >= N:
                    continue
                
                dp[lx][ly] = dp[lx][ly] + dp[x][y]

    return dp[N-1][N-1]


N = int(input())

board = [[0] * N for _ in range(N)]
dp = [[0] * N for _ in range(N)]
dp[0][0] = 1
move = [[0, 1], [1, 0]]

for i in range(N):
    board[i] = list(map(int,input().split()))


print(bottom_up(N, board, dp))
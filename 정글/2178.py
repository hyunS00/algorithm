import sys
from collections import deque

def bfs(maze, visit, pos, x, y):
    global N,M
    q = deque()
    q.append([y,x])
    visit[y][x] = True
    maze[y][x] = 1

    while q:
        y, x = q.popleft()
        for move in pos:
            move_y = y + move[0]
            move_x = x+ move[1]

            if 1 <= move_x <= M and 1 <= move_y <= N:
                if not visit[move_y][move_x] and maze[move_y][move_x]:
                    visit[move_y][move_x] = True
                    maze[move_y][move_x] = min(maze[move_y][move_x],maze[y][x]+1)
                    q.append([move_y,move_x])

N, M = map(int,sys.stdin.readline().split())

maze = [[0] * (M + 1) for _ in range(N + 1)]
visit = [[False] * (M + 1) for _ in range(N + 1)]
INF = float('inf')

for i in range(1, N+1):
    line = sys.stdin.readline().rstrip('\n')
    for j in range(1, M+1):
        if int(line[j-1]):
            maze[i][j] = INF

pos = [[0,1],[-1,0],[0,-1],[1,0]]

bfs(maze,visit,pos,1,1)

print(maze[N][M])
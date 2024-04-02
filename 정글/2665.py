import sys
import heapq
def bfs(maze, visit, start, end):
    maze[start][start] = 0
    visit[start][start] = True
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    hq =[]
    heapq.heappush(hq,(0,1,1))
    wall_crash = 0

    while hq:
        c, y, x = heapq.heappop(hq)

        if c > 0:
            wall_crash = c

        for i in range(4):
            move_x = x + dx[i] 
            move_y = y + dy[i]

            if move_x == end and move_y == end:
                return wall_crash

            if 0 < move_x <= end and 0 < move_y <= end and not visit[move_y][move_x]:

                visit[move_y][move_x] = True
                if maze[move_y][move_x] == INF:
                    heapq.heappush(hq,(wall_crash+1,move_y,move_x))
                else:
                    heapq.heappush(hq,(0,move_y,move_x))

    return wall_crash


n = int(input())

maze = [[0] * (n + 1) for _ in range(n+1)]

INF = float('inf')
visit = [[False] * (n + 1) for _ in range(n+1)]

for i in range(n):
    line = sys.stdin.readline().rstrip('\n')

    for j in range(len(line)):
        if int(line[j]) == 0:
            maze[i+1][j+1] = INF

print(bfs(maze,visit,1,n))
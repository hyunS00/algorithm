import sys
import heapq

def bfs(tube, S, X, Y):
    global hq

    move = [[0,1],[0,-1],[1,0],[-1,0]]

    while hq:
        time, virus, x, y = heapq.heappop(hq)

        if time >= S:
            return tube[X-1][Y-1]
        
        for i in range(4):
            dx, dy = move[i]

            move_y = y + dy
            move_x = x + dx

            if 0 <= move_y < N and 0 <= move_x < N:
                if tube[move_x][move_y] > 0:
                    continue

                tube[move_x][move_y] = virus
                heapq.heappush(hq,(time+1,virus, move_x, move_y))
    return tube[X-1][Y-1]

N, K = map(int, sys.stdin.readline().split())

tube = [[0] * N for _ in range(N)]


hq = []
for i in range(N):
    line = list(map(int,sys.stdin.readline().split()))
    for j in range(N):
        virus = line[j]
        if virus > 0:
            heapq.heappush(hq,(0,virus,i,j))
            tube[i][j] = virus

S, X, Y = map(int, sys.stdin.readline().split())

print(bfs(tube, S, X, Y))
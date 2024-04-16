import sys
import heapq
input = sys.stdin.readline

def bfs(tomato, hq, M, N):
    global move
    time = 0
    while hq:
        cur_time, y, x = heapq.heappop(hq)
        time = cur_time
        for dy, dx in move:
            lx = x + dx
            ly = y + dy

            if 0 <=lx < M and 0 <= ly < N:
                if tomato[ly][lx] == 0:
                    tomato[ly][lx] = 1
                    heapq.heappush(hq,(cur_time+1, ly, lx))

    for i in range(N):
        for j in range(M):
            if tomato[i][j] == 0:
                return -1
    return time
                    




M, N = map(int, input().split())

tomato = [[0] * M for _ in range(N)]
hq = []
move = [[0, 1], [0, -1], [1, 0], [-1, 0]]
for i in range(N):
    line = list(map(int, input().split()))
    for j in range(M):
        tomato[i][j] = line[j]

        if line[j] == 1:
            heapq.heappush(hq, (0, i, j))

print(bfs(tomato,hq,M,N))
import sys
import heapq

def bfs(box):
    global hq, M, N, H
    move = [[1, 0, 0], [-1, 0, 0], [0, 1, 0], [0, -1, 0], [0, 0, 1],[0, 0, -1]]
    cnt = 0
    ripe_tomato = []
    day = 0
    while hq:
        day, h, n, m = heapq.heappop(hq)

        if visit[h][n][m]:
            continue

        visit[h][n][m] = True

        for i in move:
            dh, dn, dm = i

            move_h = h + dh
            move_n = n + dn
            move_m = m + dm

            if 0 <= move_h < H and 0 <= move_n < N and 0 <= move_m < M:
                if visit[move_h][move_n][move_m]:
                    continue
                in_box = box[move_h][move_n][move_m]

                if in_box == 0:
                    box[move_h][move_n][move_m] = 1
                    heapq.heappush(hq, (day + 1,move_h, move_n, move_m))

    for h in range(H):
        for n in range(N):
            for m in range(M):
                if box[h][n][m] == 0:
                    return -1
    return day

# 가로:M 세로:N 높이:H
M, N, H = map(int, sys.stdin.readline().split())

box = [[[0]*M for _ in range(N)] for _ in range(H)]
visit = [[[False]*M for _ in range(N)] for _ in range(H)]
hq = []

for h in range(H):
    for n in range(N):
        line = list(map(int,sys.stdin.readline().split()))
        for m in range(M):
            box[h][n][m] = line[m]
            
            if line[m] == 1:
                heapq.heappush(hq,(0,h,n,m))

print(bfs(box))
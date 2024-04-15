import sys
from collections import deque
input = sys.stdin.readline

def bfs(board, visit, start_x, start_y):
    global cnt, move, M, N, q

    if visit[start_x][start_y]:
        return
    visit[start_x][start_y] = True

    if not board[start_x][start_y]:
        return
    q.append((start_x, start_y))
    cnt += 1
    while q:
        x, y = q.pop()
        for dx, dy in move:
            lx = x + dx
            ly = y + dy

            if 0 <= lx < M and 0<= ly < N:
                if visit[lx][ly]:
                    continue
                
                visit[lx][ly] = True
                if board[lx][ly]:
                    q.append((lx,ly))


T = int(input())
move = [[1, 0], [-1, 0], [0, 1], [0, -1]]

for _ in range(T):
    M, N, K = map(int,input().split())
    board = [[0] * N for _ in range(M)]
    visit = [[False] * N for _ in range(M)]
    cnt = 0
    q = deque()
    for _ in range(K):
        X, Y = map(int, input().split())
        board[X][Y] = 1

    for x in range(M):
        for y in range(N):
            if not visit[x][y]:
                bfs(board, visit, x, y)
    print(cnt)
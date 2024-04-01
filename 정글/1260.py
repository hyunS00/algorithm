import sys
from collections import deque

def dfs(v):
    global graph, dfs_result, visit,N

    if visit[v]:
        return
    
    visit[v] = True
    dfs_result.append(str(v))

    if len(dfs_result) >=N:
        return
    
    for node in graph[v]:

        if visit[node]:
            continue
        dfs(node)

    return

def bfs(v):
    global graph, q, bfs_result, visit

    q.append(v)
    visit[v] = True
    bfs_result.append(str(v))
    while q:
        now = q.popleft()
        for node in graph[now]:
            if visit[node]:
                continue

            visit[node] = True
            bfs_result.append(str(node))
            q.append(node)

    return


N, M, V = map(int,sys.stdin.readline().split())

graph = [[] for _ in range(N+1)]

for _ in range(M):
    v1, v2 = map(int,sys.stdin.readline().split())
    graph[v1].append(v2)
    graph[v2].append(v1)

for i in range(N+1):
    graph[i].sort()

visit = [False] * (N+1)
dfs_result = []
dfs(V)

visit = [False] * (N+1)
q = deque()
bfs_result = []
bfs(V)

print(' '.join(dfs_result))
print(' '.join(bfs_result))
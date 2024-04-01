import sys
from collections import deque

def dijkstra(graph,dist,start):
    q = deque()
    dist[start] = 0
    
    q.append(start)

    while q:
        now = q.popleft()

        for node in graph[now]:
            cost = dist[now]+1
            if cost < dist[node]:
                dist[node] = cost
                q.append(node)

    
N, M, K, X = map(int,sys.stdin.readline().split())

graph = [[] for _ in range(N+1)]

INF = float('inf')
dist = [INF] * (N+1)
for _ in range(M):
    a, b = map(int,sys.stdin.readline().split())
    graph[a].append(b)

dijkstra(graph,dist,X)

have_k = False
for idx,i in enumerate(dist):
    if i == K:
        print(idx)
        have_k = True
if not have_k:
    print(-1)
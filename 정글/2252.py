import sys
from collections import deque

def bfs(graph, indegree, remove):
    global q

    while q:
        now = q.popleft()
        remove[now] = True
        print(now, end=" ")

        for node in graph[now]:
            if not remove[node]:
                indegree[node] -= 1
                
                if indegree[node] == 0:
                    q.append(node)
                    remove[node] = True


N, M = map(int, sys.stdin.readline().split())

indegree = [0] * (N + 1)

graph = [[] for _ in range(N + 1)]

remove = [False] * (N + 1)

for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    graph[A].append(B)
    indegree[B] += 1

q = deque()

for i in range(1,N+1):
    if indegree[i] == 0:
        q.append(i)

bfs(graph,indegree,remove)
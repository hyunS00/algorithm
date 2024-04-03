import sys
from collections import deque

def bfs(graph, indegree, count, start):
    count[start] = 1
    q = deque()

    q.append(start)
   

    while q:
        now = q.popleft()

        for node in graph[now]:
            next, cost = node

            indegree[next] -= 1
            count[next] += count[now] * cost
            if indegree[next] <= 0:
                q.append(next)

N = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]
indegree = [0] * (N + 1)
count = [0] * (N + 1)

for _ in range(M):
    X, Y, K = map(int,sys.stdin.readline().split())
    graph[X].append([Y, K])
    indegree[Y] += 1

bfs(graph,indegree,count,N)

for i in range(1,N):
    if not graph[i]:
        print(f'{i} {count[i]}')
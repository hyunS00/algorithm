import sys
import heapq

def dijkstra(graph, dist, start):
    hq = []
    heapq.heappush(hq,(0, start))

    dist[start] = 0

    while hq:
        now_cost, now = heapq.heappop(hq)
        if dist[now] != now_cost:
            continue

        for node in graph[now]:
            cost = now_cost + node[0]
            if cost < dist[node[1]]:
                dist[node[1]] = cost
                heapq.heappush(hq,(cost, node[1]))


N = int(input())
M = int(input())

graph = [[] for _ in range(N+1)]

INF = float('inf')
dist = [INF] * (N+1)

for _ in range(M):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((c,b))

start, end = map(int,sys.stdin.readline().split())

dijkstra(graph,dist,start)

print(dist[end])
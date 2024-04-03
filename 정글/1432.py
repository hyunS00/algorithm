import sys
import heapq

def bfs(graph, in_degree, hq):
    cnt = N+1

    while hq:
        now = -heapq.heappop(hq)
        cnt -= 1
        result[now-1] = cnt

        for node in graph[now]:
            in_degree[node] -= 1

            if in_degree[node] <= 0:
                heapq.heappush(hq,-node)
    return


N = int(input())

graph = [[] for _ in range(N+1)]
in_degree = [0] * (N+1)
result = [0] * N

is_break = False
for i in range(1,N+1):
    line = sys.stdin.readline().rstrip('\n')
    
    for j in range(N):
        if line[j] == '1':

            graph[j+1].append(i)
            in_degree[i] += 1

hq = []
for i in range(1,N+1):
    if in_degree[i] == 0:
        heapq.heappush(hq,-i)

bfs(graph,in_degree, hq)

for i in range(N):
    if result[i] == 0:
        print(-1)
        break
else:
    print(*result)
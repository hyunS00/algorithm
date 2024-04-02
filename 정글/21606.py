import sys

def dfs(graph, visit, now,start):
    global in_out,cnt
    
    visit[now] = True
    if now != start and in_out[now] == 1:
        cnt += 1
        return

    for node in graph[now]:
        if not visit[node]:
            dfs(graph, visit, node, start)
    return

N = int(input())
line = sys.stdin.readline().rstrip('\n')

graph = [[] for _ in range(N+1)]
in_out = [0] *(N+1)
visit = [False] *(N+1)

for _ in range(N-1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for idx, i in enumerate(line):
    in_out[idx+1] = int(i)

cnt = 0
for i in range(1, N+1):
    
    if in_out[i]:
        visit = [False] *(N+1)
        start = i
        dfs(graph,visit,i,start)
print(cnt)
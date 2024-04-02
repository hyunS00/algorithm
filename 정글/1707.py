import sys
sys.setrecursionlimit(10**6)

def dfs(graph, union, cur,group):
    global is_break
    if union[cur] >= 0 or is_break:
        return
    
    union[cur] = group

    if group:
        group = 0
    else:
        group = 1

    for node in graph[cur]:
        if union[node] == union[cur] and not is_break:
            is_break = True
            return
        dfs(graph, union, node, group)

K = int(input())

while K:
    K -= 1

    V, E = map(int,sys.stdin.readline().split())

    graph = [set() for _ in range(V + 1)]
    union = [-1] * (V + 1)

    for _ in range(E):
        u, v = map(int, sys.stdin.readline().split())
        graph[u].add(v)
        graph[v].add(u)

    is_break = False
    for i in range(1,V+1):
        dfs(graph,union,i,0)
        if is_break:
            print("NO")
            break
    else:
        print("YES")


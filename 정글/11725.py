# 유니온 파인드로 접근했지만 실패
# import sys
# sys.setrecursionlimit(10**6)
# def find_parent(parent, x):
#     if parent[x] != x:
#         parent[x]= find_parent(parent,parent[x])
#     return parent[x]

# def union_parent(grand_parent,parent, a, b):
#     a_parent = 0
#     b_parent = 0

#     if a > b:
#         a, b = b, a
        
#     if a != 1:
#         a_parent = find_parent(grand_parent,a)

#     b_parent = find_parent(grand_parent,b)
    
#     if rank[a_parent] >= rank[b_parent]:
#         grand_parent[b_parent] = a_parent
#         parent[b] = a
#     else:
#         grand_parent[a_parent] = b_parent
#         parent[a] = b
    
#     if rank[a_parent] == rank[b_parent]:
#         rank[a_parent] += 1

# N = int(input())

# grand_parent = [i for i in range(N+1)]
# parent = [i for i in range(N+1)]
# rank = [0 for i in range(N+1)]

# for _ in range(N-1):
#     a, b = map(int,sys.stdin.readline().split())
#     union_parent(grand_parent,parent,a, b)

# for i in range(2,N+1):
#     print(parent[i])

import sys
sys.setrecursionlimit(10**6)

def dfs(graph,visit,parent,node):
    global cnt
    cnt +=1

    if node == None:
        return
    
    visit[node] = True
    for child in graph[node]:
        if not visit[child]:
           result_child = dfs(graph,visit,parent,child)
           parent[result_child] = node

    return node

N = int(input())

visit = [False] * (N+1)
graph = [[] for _ in range(N+1)]
parent = [i for i in range(N+1)]

for _ in range(N-1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

cnt = 0

dfs(graph,visit,parent,1)

for i in range(2,N+1):
    print(parent[i])
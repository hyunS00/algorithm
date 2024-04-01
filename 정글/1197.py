import sys
import heapq

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent,parent[x])

    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

V, E = map(int,sys.stdin.readline().split())

parent = [i for i in range(V+1)]
cost = []
sum = 0
cnt = 0
for _ in range(E):
    A, B, C = map(int,sys.stdin.readline().split())
    heapq.heappush(cost,(C, A, B))

while cnt < V-1 and cost:
    c, a, b = heapq.heappop(cost)

    a = find_parent(parent,a)
    b = find_parent(parent,b)

    if a != b:
        union_parent(parent,a,b)
        cnt += 1
        sum += c

print(sum)
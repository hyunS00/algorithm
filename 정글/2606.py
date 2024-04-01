import sys

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent,parent[x])
    
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

v = int(input())
e = int(input())

parent = [i for i in range(v+1)]

for _ in range(e):
    a, b = map(int,sys.stdin.readline().split())
    union_parent(parent, a, b)

one_parent = find_parent(parent, 1)
cnt = 0
for node in parent:
    node_parent = find_parent(parent, node)
    if node_parent == one_parent:
        cnt += 1

print(cnt-1)
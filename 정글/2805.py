import sys

def cut_tree(tree,meter):
    sum = 0
    i = len(tree)-1

    while tree[i] > meter and i >= 0:
        sum += tree[i] - meter
        i -= 1

    return sum

def binary_search(tree,start,end):
    global M,heigt
    mid = int((start + end) / 2)
    if mid < start or mid > end:
        return mid
    
    tree_cnt = cut_tree(tree,mid)
    if tree_cnt == M:
        return mid
    elif tree_cnt < M:
        return binary_search(tree, start,mid-1)
    else:
        return binary_search(tree,mid+1, end)

N, M = list(map(int,sys.stdin.readline().split()))
tree = list(map(int,sys.stdin.readline().split()))

tree.sort()
print(tree)

print(binary_search(tree,0,tree[len(tree)-1]))
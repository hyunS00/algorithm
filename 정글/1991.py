import sys

N = int(input())

def ascii_code(x):
    code = ord(x) - 64
    if code < 0:
        code = 0
    return code

def preorder(index,pre,mid,end):
    
    pre.append(chr(index+64))

    if node[index][0] != 0:
        preorder(node[index][0],pre,mid,end)
        node[index][0] = 0

    mid.append(chr(index+64))

    if node[index][1] != 0 :
        preorder(node[index][1],pre,mid,end)
        node[index][1] = 0

    end.append(chr(index+64))


node_list = [list(map(ascii_code,sys.stdin.readline().split())) for i in range(N)]

node = [[0] * 2 for i in range(N+1)]

for i in range(0,N):
    node[node_list[i][0]] = node_list[i][1:]

pre = []
mid = []
end = []

preorder(1,pre,mid,end)

print(''.join(pre))
print(''.join(mid))
print(''.join(end))
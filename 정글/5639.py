import sys
sys.setrecursionlimit(10**9)

pre = []
while True:
    try:
        node = sys.stdin.readline().rstrip('\n')

        if node == "":
            break

        pre.append(int(node))

    except EOFError:
        break


def order(pre):
    if len(pre) <= 0:
        return
    
    root = pre[0]

    for i in range(1, len(pre)):
        if root <= pre[i]:
            left = pre[1:i]
            right = pre[i:]
            break
    else:
        left = pre[1:]
        right = []
    
    order(left)
    order(right)
    print(root)

order(pre)

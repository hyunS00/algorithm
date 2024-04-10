import sys
input = sys.stdin.readline

def check(S, x):
    x = int(x)
    num = (1 << x)

    if S & num:
        return 1
    else:
        return 0

def add(S, x):
    x = int(x)

    if not check(S,x):
        S |= (1 << x)
    return S

def remove(S, x):
    x = int(x)

    if check(S,x):
        S &= ~(1 << x)
    return S

def toggle(S, x):
    x = int(x)
    
    S ^= (1 << x)
    return S

def all(S):
    S = (1 << 21)-1
    return S

def empty(S):
    S = 0
    return S

M = int(input())
S = 0

for _  in range(M):
    command = input().split()
    com = command[0]

    if com == "add":
        S = add(S, command[1])
    elif com == "check":
        print(check(S, command[1]))
    elif com == "remove":
        S = remove(S, command[1])
    elif com == "toggle":
        S = toggle(S, command[1])
    elif com == "all":
        S = all(S)
    elif com == "empty":
        S = empty(S)
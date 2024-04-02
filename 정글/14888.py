import sys
sys.setrecursionlimit(10**6)

def calculate(oper, a, b):
    if oper == 0:
        return a + b
    
    if oper == 1:
        return a - b
    
    if oper == 2:
        return a * b
    
    if oper == 3:
        return int(a / b)

def calculateA(oper,A):
    a = A[0]
    for idx, i in enumerate(oper):
        a = calculate(i,a,A[idx+1])
    return a
       


def dfs(operator):
    global A, N, result,small,big

    if len(result) >= N-1:
        res = calculateA(result,A)
        small = min(small, res)
        big = max(big, res)
        return
    

    for idx, i in enumerate(operator):
        if i > 0:
            operator[idx] -= 1
            result.append(idx)

            dfs(operator)

            operator[idx] += 1
            result.pop()
            


N = int(input())

A = list(map(int,sys.stdin.readline().split()))

plus, minus, multiple, divide = map(int,sys.stdin.readline().split())

operator = [plus,minus,multiple,divide]

result = []
INF = float('inf')
small = INF
big = -INF
op = ['+','-','*','/']
dfs(operator)

print(big)
print(small)
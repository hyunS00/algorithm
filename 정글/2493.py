import sys

N = int(input())

top_input = list(map(int,sys.stdin.readline().split()))
top_list = list([i+1,top_input[i]] for i in range(N))

request =[0]*N
stack = []
top = -1

stack.append(top_list[0])
top += 1

for i in range(1,N):
    while top >= 0 and stack[top][1] < top_list[i][1]:
        stack.pop()
        top -= 1
    if top >= 0:
        request[i] = stack[top][0]

    stack.append(top_list[i])
    top += 1

ans = " ".join(list(map(str,request)))
print(ans)
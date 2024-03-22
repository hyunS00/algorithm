def fact(N):
    if N == 0:
        num = 0
    
    num = 1
    for i in range(2,N+1):
        num *= i

    return num

N = int(input())


answer = fact(N)
print(answer)
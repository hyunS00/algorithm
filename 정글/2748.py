# top-down
# def fibo(n):
#     global dp

#     if n == 2 or n == 1:
#         return 1
    
#     if dp[n] != 0:
#         return dp[n]
    
#     dp[n] = fibo(n-1) + fibo(n-2)

#     return dp[n]

# N = int(input())

# dp = [0] * 91
# dp[1] = 1
# dp[2] = 1

# print(fibo(N))

# bottom-up
def fibo(N):
    dp = [0] * 90
    dp[0] = 1
    dp[1] = 1

    for i in range(2,N):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[N-1]

N = int(input())

print(fibo(N))
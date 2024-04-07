# dfs
# import sys
# sys.setrecursionlimit(10**6)

# def dfs(N,tile_cnt):
#     global cnt

#     if tile_cnt >= N:
#         cnt += 1

#     if N -  tile_cnt >= 2:
#         tile(N,tile_cnt+2)
#     if N - tile_cnt >= 1:
#         tile(N,tile_cnt+1)

# N = int(input())

# cnt = 0
# dfs(N,0)
# print(cnt)

# top - down
# 시간 초과
# import sys
# sys.setrecursionlimit(10**6)

# def dfs(n):
#     a, b = 0, 0
#     if n <= 2:
#         return n
    
#     if dp[n] != 0:
#         return dp[n]
    
#     if dp[n-1] != 0:
#         a = dp[n-1]
#     a = dfs(n-1)

#     if dp[n-2] != 0:
#         b = dp[n-2]
#     b = dfs(n-2)

#     dp[n] = (a + b) % 15746

#     return dp[n]

# N = int(input())

# dp = [0] * 1000001
# dp[1] = 1
# dp[2] = 2

# print(dfs(N))

# bottom-up
import sys
sys.setrecursionlimit(10**6)

def tile(N):
    dp = [0] * 1000001
    dp[1] = 1
    dp[2] = 2
    
    for i in range(3,N+1):
        dp[i] = (dp[i-1] + dp[i-2]) % 15746
        
    return dp[N] % 15746

   
N = int(input())

print(tile(N))
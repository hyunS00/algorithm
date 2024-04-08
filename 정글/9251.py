import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# 재귀
# def LCS(A, B):
#     i, j = len(A), len(B)
#     if i <= 0 or j <= 0 :
#         return 0
#     if A[-1] == B[-1]:
#         return LCS(A[:i-1], B[:j-1]) + 1
    
#     return max(LCS(A,B[:j-1]),LCS(A[:i-1],B))

# A = input().rstrip()
# B = input().rstrip()

# print(LCS(A,B))

# dp top-down
# def LCS(A, B):
#     global dp
#     i, j = len(A), len(B)
#     if i <= 0 or j <= 0 :
#         return 0
    
#     if A[-1] == B[-1]:
#         if dp[i][j] == 0:
#             dp[i][j] = LCS(A[:i-1], B[:j-1]) + 1

#         return dp[i][j]
    
#     return max(LCS(A,B[:j-1]),LCS(A[:i-1],B))

# A = input().rstrip()
# B = input().rstrip()
# dp = [[0]* 1000 for _ in range(1000)]
# print(LCS(A,B))

# dp bottom-up

def LCS(A, B):
    global dp
    n, m = len(A), len(B)
    A = ' ' + A
    B = ' ' + B

    for i in range(1, n+1):
        for j in range(1, m+1):
            if A[i] == B[j]:
                dp[i][j] = dp[i-1][j-1] + 1
            elif dp[i][j-1] >= dp[i-1][j]:
                dp[i][j] = dp[i][j-1]
            else:
                dp[i][j] = dp[i-1][j]
    
    return dp[n][m]

A = input().rstrip()
B = input().rstrip()
dp = [[0]* 1001 for _ in range(1001)]
print(LCS(A,B))
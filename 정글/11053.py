import sys
input = sys.stdin.readline

def LCS(A, s, m, n):
    for i in range(1, n):
        for j in range(1, m):
            if s[i] == A[j]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

N = int(input().rstrip())

A = list(map(int,input().split()))
A = [0] + A
s = set()

for num in A:
    s.add(num)
s = list(s)
s.sort()
m, n = len(A), len(s)

dp = [[0] * m for _ in range(n)]

LCS(A, s, m, n)
print(dp[n-1][m-1])
import sys

input = list(map(int,sys.stdin.readline().split()))
A = input[0]
B = input[1]

print(A+B)
print(A-B)
print(A*B)
print(int(A/B))
print(A%B)
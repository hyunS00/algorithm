import sys
input = sys.stdin.readline

N = int(input())

mul5 = int(N / 5)
mul25 = int(N / 25)
mul125 = int(N / 125)

print(mul5 + mul25 + mul125)
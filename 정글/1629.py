import sys

def multiple(a,b,c):
    if b == 1:
        return a % c

    mod = multiple(a,b//2,c)
    if b % 2 == 0:
        return (mod * mod) % c
    else:
        return (mod * mod * a) % c

A, B, C = list(map(int,sys.stdin.readline().split()))
print(multiple(A,B,C))
import sys
from collections import deque

N, K = list(map(int,sys.stdin.readline().split()))

peaple = deque(i+1 for i in range(N))

ans = []

i = 0
while peaple:
    i += 1
    if i % K == 0:
        ans.append(peaple.popleft())
    else:
        peaple.append(peaple.popleft())

join_str =', '.join(map(str,ans))
print(f'<{join_str}>')
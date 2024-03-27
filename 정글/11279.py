import sys
import heapq

N = int(input())

x_list = [int(sys.stdin.readline()) for i in range(N)]

heap = []

for x in x_list:
    if x == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(-heapq.heappop(heap))
    else:
        heapq.heappush(heap,-x)
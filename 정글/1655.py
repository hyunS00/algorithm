import sys
import heapq

N = int(input())

num_list = [int(sys.stdin.readline()) for i in range(N)]

min_heap = []
max_heap = []
mid = num_list[0]
print('시작',mid)
for i in range(1,N):
    num = num_list[i]
    if (i+1) % 2 == 0:
        # 미드 값이 num보다 작으면 최대힙에 미드 최소 힙에 num
        if mid < num:
            heapq.heappush(max_heap,-mid)
            heapq.heappush(min_heap,num)
        else:
            heapq.heappush(min_heap,mid)
            heapq.heappush(max_heap,-num)
        mid = -max_heap[0]

    else :
        tmp = None
        if num < mid:
            heapq.heappush(max_heap,-num)
            mid = -heapq.heappop(max_heap)
        else:
            heapq.heappush(min_heap,num)
            mid = heapq.heappop(min_heap)
    print(mid)
import sys
import heapq

N = int(input())

num_list = [int(sys.stdin.readline()) for i in range(N)]

heap = []

for num in num_list:
    heapq.heappush(heap,num)
    heap_size = len(heap)+1

    pop_value = []
    for i in range(heap_size//2):
        pop_value.append(heapq.heappop(heap))

    print(pop_value[len(pop_value)-1])

    for value in pop_value:
        heapq.heappush(heap, value)
    
    print(heap)
import sys
import heapq
input = sys.stdin.readline

def greedy(lecture, hq):
    cnt = 1
    start, end, number = lecture[0]
    heapq.heappush(hq,end)
    for i in range(1, N):
        start, end, number = lecture[i]
        end_point = heapq.heappop(hq)

        if end_point <= start:
            heapq.heappush(hq,end)
        else:
            cnt += 1
            heapq.heappush(hq,end)
            heapq.heappush(hq,end_point)
    
    return cnt


N = int(input())

lecture = []
hq = []
for _ in range(N):
    n, s, e = map(int,input().split())
    lecture.append((s, e, n))

lecture.sort()
print(greedy(lecture, hq))
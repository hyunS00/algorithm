import sys
import heapq
input = sys.stdin.readline

def greedy(lecture, room):
    hq = []
    start, end, lecture_num = lecture[0]
    cnt = 1
    room[lecture_num] = cnt
    heapq.heappush(hq,(end, cnt, lecture_num))
    
    for i in range(1, K):
        start, end, lecture_num = lecture[i]
        min_end, min_room, min_lecture = heapq.heappop(hq)

        if start >= min_end:
            room[lecture_num] = min_room
            heapq.heappush(hq, (end, min_room, lecture_num))
        else:
            cnt += 1
            room[lecture_num] = cnt
            heapq.heappush(hq, (end, cnt, lecture_num))
            heapq.heappush(hq, (min_end, min_room, min_lecture))

    return cnt, room

K = int(input())

lecture = []
room = [0] * (K+1)
for _ in range(K):
    number, start, end = map(int,input().split())
    lecture.append((start, end, number))

lecture.sort()
room_cnt, room = greedy(lecture, room)

print(room_cnt)
for i in range(1,K+1):
    print(room[i])
import sys

def find_safty_area(n, length):
    global N, visit, area, cnt
    if n > N-1:
        return
    
    for i in range(N):
        if visit[n][i]:
            return
        
        if area[n][i] <= length:
            cnt += 1
            continue
        
        visit[n][i] = True
        print( n, i)
        find_safty_area(n+1, length)
    if area[n][N-1] > length:
        cnt += 1


N = int(input())

area = [list(map(int,sys.stdin.readline().split())) for i in range(N)]
visit = [[False]*N for i in range(N)]
cnt =0
print(area)

find_safty_area(0,4)

print(cnt)
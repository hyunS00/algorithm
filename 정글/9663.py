def queen(cnt,y,N):
    if y == N:
        cnt[0] += 1
        return
    
    for i in range(N):
        if x_chess[i] or up_chess[i+y] or down_chess[y-i+N-1]:
            continue
        
        x_chess[i] = True
        up_chess[i+y] = True
        down_chess[y-i+N-1] = True

        queen(cnt,y+1,N)

        x_chess[i] = False
        up_chess[i+y] = False
        down_chess[y-i+N-1] = False


N = int(input())

x_chess = [False] * N
up_chess = [False] * (N * 2 -1)
down_chess = [False] * (N * 2-1)

cnt = [0]
queen(cnt,0,N)
print(cnt[0])
import sys

def find_cut_paper(start_x, end_x, start_y, end_y):
    global paper, white, blue
    if end_x - start_x <= 0 and end_y - start_y <= 0:
        if paper[start_y][start_x]:
            blue +=1
        else:
            white +=1
        return
    
    sum = 0
    for y in range(start_y, end_y+1):
        for x in range(start_x, end_x+1):
            sum += paper[y][x]
    
    if (end_x+1 - start_x) * (end_y+1 - start_y) == sum or sum == 0:
        if sum > 0:
            blue += 1
        else:
            white +=1
        return
    

    mid_x = (end_x + start_x) // 2
    mid_y = (end_y + start_y) // 2

    find_cut_paper(start_x, mid_x, start_y, mid_y)
    find_cut_paper(mid_x+1, end_x, start_y, mid_y)
    find_cut_paper(start_x, mid_x, mid_y+1, end_y)
    find_cut_paper(mid_x+1, end_x, mid_y+1, end_y)

N = int(input())

paper = [list(map(int,sys.stdin.readline().split())) for i in range(N)]
white = 0
blue = 0
cnt = 0

find_cut_paper(0,N-1,0,N-1)
print(white)
print(blue)
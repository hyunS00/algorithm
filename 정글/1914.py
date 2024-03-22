def hanoi(disk,start, middle, end):
    if disk == 0:
         return
    hanoi(disk-1, start, end, middle)
    print(f'{start} {end}')
    hanoi(disk-1, middle, start, end)


N = int(input())
process = (2**N - 1)

print(process)
if N  <= 20:
    hanoi(N,1,2,3)
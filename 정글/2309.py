import sys

dwarf = [int(sys.stdin.readline()) for i in range(9)]

sort_dwarf = sorted(dwarf)

total_tall = sum(sort_dwarf)

find_tall = total_tall - 100

find_dwarf = []
for i in range(8):
    for j in range(i+1,9):
        if sort_dwarf[i] + sort_dwarf[j] == find_tall:
            for k in range(9):
                if k == i or k == j:
                    continue
                find_dwarf.append(sort_dwarf[k])
            break
    if len(find_dwarf) == 7:
        break

for i in find_dwarf:
    print(i)
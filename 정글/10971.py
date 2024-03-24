import sys

def tsp(n):
    global city, visit, cost, min
    if n < 1:
        sum = 0
        for i in range(len(city)-1):
            visit_cost = cost[city[i]][city[i+1]]
            if visit_cost == 0 :
                return
            sum += visit_cost
        visit_cost = cost[city[len(city)-1]][city[0]]
        if visit_cost == 0 :
            return
        sum += visit_cost

        if min > sum :
            min = sum
        return
    for i in range(N):
        if visit[i]:
            continue
        city.append(i)
        visit[i] = True

        tsp(n-1)

        city.pop()
        visit[i] = False

    return
    



N = int(input())
cost = [list(map(int,sys.stdin.readline().split())) for i in range(N)]

visit = [0] * N
city = []
min = 10000000

tsp(N)

print(min)
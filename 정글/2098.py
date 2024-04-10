import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

inf = float('inf')

def tsp(start, visit):
    global N, graph, dp

    # 모든 도시를 방문했다면
    if visit >= (1 << N) - 1:
        if graph[start][0]: ## 시작점으로 돌아갈 수 있다면
            return dp[start][visit] + graph[start][0]
        else: ## 시작점으로 돌아갈 수 없다면 돌아갈 수 없으니 inf 리턴
            return inf

    # 이미 업데이트 된 값이 있다면 업데이트값 리턴
    if dp[start][visit] > 0:
        return dp[start][visit]
    
    # 최소 거리를 구하기 위한 min_val 초기화
    min_val = inf
    for next in range(1,N):
        # 시작점 도시에서 도착점 도시로 갈 수 없거나 이미 방문 했다면 continue
        if graph[start][next] == 0 or visit & (1 << next):
            continue
        
        # 방문한 도시 visit 처리
        visit |= (1 << next)

        # 기존 저장된 값과 시작 도시에서 next도시로 가는 값 + 재귀를통해 next에서 시작해 다른 도시로 도착한 거리중 최솟값 업데이트
        min_val = min(min_val, graph[start][next] + tsp(next, visit))

        # 방문한 도시에서 나왔으니까 다시 visit 원래대로
        visit &= ~(1 << next)

    # 시작점에서 visit(예를들어 0011)한 도시들 최솟값 기록
    dp[start][visit] = min_val
    # dp 값 리턴
    return dp[start][visit]



N = int(input())

graph = []

for _ in range(N):
    line = list(map(int, input().split()))
    graph.append(line)

dp = [[0] * (1 << N) for _ in range(N)]
visit = 1

print(tsp(0, visit))
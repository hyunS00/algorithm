#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define COST first
#define VERTEX second
using namespace std;

const int INF = 1e9 + 10;
int n, m, x;
// 비용, 도시
vector<pair<int, int>> adj[1005];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int d[1005];
int cost[1005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x;
    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({t, b});
    }
    
    fill(cost, cost+1+n, INF);
    cost[x] = 0;
    pq.push({cost[x], x});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cost[cur.VERTEX] != cur.COST) continue;
        for(auto nxt : adj[cur.VERTEX]){
            if(cost[nxt.VERTEX] <= cost[cur.VERTEX] + nxt.COST) continue;
            cost[nxt.VERTEX] = cost[cur.VERTEX] + nxt.COST;
            pq.push({cost[nxt.VERTEX], nxt.VERTEX});
        }
    }

    for(int st = 1; st <= n; st++){
        fill(d, d+1+n, INF);
        d[st] = 0;
        pq.push({d[st], st});
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(d[cur.VERTEX] != cur.COST) continue;
            for(auto nxt : adj[cur.VERTEX]){
                if(d[nxt.VERTEX] <= d[cur.VERTEX] + nxt.COST) continue;
                d[nxt.VERTEX] = d[cur.VERTEX] + nxt.COST;
                pq.push({d[nxt.VERTEX], nxt.VERTEX});
            }
        }
        cost[st] += d[x];
    }

    cout << *max_element(cost+1, cost+n+1);
}
#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

const int INF = 200000000;
int n, m, v1, v2;

vector<pair<int, int>>adj[805];

vector<int> solve(int st){
    vector<int> d(n+1, INF);
    d[st] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({d[st], st});

    while(!pq.empty()){
        int cost, cur;
        tie(cost, cur) = pq.top(); pq.pop();
        if(d[cur] != cost) continue;

        for(auto nxt : adj[cur]){
            if(d[nxt.second] <= d[cur] + nxt.first) continue;
            d[nxt.second] = d[cur] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }

    return d;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;

    vector<int> st_dist = solve(1);
    vector<int> v1_dist = solve(v1);
    vector<int> v2_dist = solve(v2);

    int ans = 0;
    int mn = st_dist[v1] + v1_dist[v2] + v2_dist[n];
    mn = min(mn, st_dist[v2] + v2_dist[v1] + v1_dist[n]);
    ans += mn;

    if(ans >= INF) ans = -1;
    cout << ans;
}
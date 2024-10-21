#include<iostream>
#include<queue>
#include<vector>
#define C first
#define V second
using namespace std;

const int INF = 1e9+10;
int n, m, st, en;
vector< pair<int, int> > adj[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
int d[1005];
int pre[1005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;

    fill(d, d+1+n,INF);

    d[st] = 0;
    PQ.push({0, st});
    while (!PQ.empty()) {
        auto cur = PQ.top(); PQ.pop();
        if(d[cur.V] != cur.C) continue;
        for(auto nxt : adj[cur.V]){
            if(d[nxt.V] <= d[cur.V]+nxt.C) continue;
            d[nxt.V] = d[cur.V]+nxt.C;
            PQ.push({d[nxt.V], nxt.V});
            pre[nxt.V] = cur.V;
        }
    }

    vector<int> path;
    int cur = en;
    while (cur != st){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);

    cout << d[en] << endl;
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for(auto x : path) cout << x << " ";
}
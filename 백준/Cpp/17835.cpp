#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 0x7f7f7f7f7f7f;

int n, m, k;
vector<pair<ll, int>> adj[100005];
ll d[100005];
priority_queue< pair<ll,int>,
                vector<pair<ll,int>>,
                greater<pair<ll,int>>> pq;

void solve(){
    while(!pq.empty()){
        int cur_n, nxt_n;
        ll cur_w, nxt_w;
        tie(cur_w, cur_n) = pq.top(); pq.pop();
        if(cur_w != d[cur_n]) continue;
        for(auto nxt : adj[cur_n]){
            tie(nxt_w, nxt_n) = nxt;
            if(d[nxt_n] <= d[cur_n] + nxt_w) continue;
            d[nxt_n] = d[cur_n] + nxt_w;
            pq.push({d[nxt_n], nxt_n});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    fill(d+1, d+1+n,INF);
    while(m--){
        int u, v;
        ll c;
        cin >> u >> v >> c;
        adj[v].push_back({c, u});
    }

    int ct;
    while (k--) {
        cin >> ct;
        d[ct] = 0;
        pq.push({0, ct});
    }

    solve();

    int idx = max_element(d+1, d+1+n) - d;
    cout << idx << endl << d[idx];
}
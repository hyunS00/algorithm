#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
using namespace std;

int n;
vector<int> adj[51];
int depth[51];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    while (true) {
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int mn = n;
    int cnt = 0;
    for(int i = 1; i <= 50; i++){
        if(adj[i].empty()) continue;

        queue<int> Q;
        int dist[51] = {0};
        dist[i] = 1;
        Q.push(i);

        int mx = 1;
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int nxt : adj[cur]){
                if(dist[nxt] > 0) continue;
                dist[nxt] = dist[cur]+1;
                mx = max(mx, dist[cur]);
                Q.push(nxt);
            }
        }
        if(mn == mx) cnt++;
        else if(mx < mn){mn = mx; cnt = 1;}
        depth[i] = mx;
    }

    cout << mn << " " << cnt << endl;
    for(int i = 1; i <= 50; i++){
        if(depth[i] == mn) cout << i << " ";
    }
}
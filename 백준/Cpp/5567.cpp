#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, ans;
queue<int> Q;
vector<int> adj[505];
int dist[505];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Q.push(1);
    dist[1] = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(dist[cur] > 2) continue;
        for(int next : adj[cur]){
            if(dist[next] > 0) continue;
            dist[next] = dist[cur]+1;
            ans++;
            Q.push(next);
        }
    }
    cout << ans;
}   
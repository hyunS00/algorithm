#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

void dfs(int cur, int prev, bool &isTree,  vector<vector<int>> adj, vector<bool> visited){
    for(int nxt : adj[cur]){
        if(nxt == prev) continue;
        if(visited[nxt]){
            isTree = false;
            continue;
        }
        dfs(nxt, cur, isTree, adj, visited);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int idx = 0;
    while (true) {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        idx++;

        vector<vector<int>> adj(n+1, vector<int>());
        vector<bool> visited(n+1, false);

        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(visited[i]) continue;
            visited[i] = true;
            bool isTree = true;
            dfs(i, 0, isTree, adj, visited);
            cnt += isTree;
        }

        cout << "Case " << idx << ": ";
        
        if(cnt == 0) cout << "No trees.";
        else if(cnt == 1) cout << "There is one tree.";
        else cout << "A forest of " << cnt << " trees.";
    }
}
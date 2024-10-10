#include<iostream>
#include<queue>
#include<vector>
#define endl "\n"
using namespace std;

int n, m;
vector<int> adj[1005];
int deg[1005];
queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        int a, b;
        cin >> a;
        for(int j = 0; j < k-1; j++){
            cin >> b;
            adj[a].push_back(b);
            deg[b]++;
            a = b;
        }
    }

    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) Q.push(i);

    vector<int> ans;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        ans.push_back(cur);

        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) Q.push(nxt);
        }
    }

    for(int i = 1; i <= n; i++){
        if(deg[i]){
            cout << 0;
            return 0;
        }
    }

    for(auto i : ans)
        cout << i << endl;
}
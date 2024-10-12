#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int> adj[32005];
int deg[32005];
priority_queue<int> PQ;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    for(int i = 1; i<= n; i++)
        if(deg[i] == 0) PQ.push(-i);

    
    while(!PQ.empty()){
        int cur = -PQ.top(); PQ.pop();
        cout << cur << " ";
        for(int nxt : adj[cur]){
            if(--deg[nxt] == 0) PQ.push(-nxt);
        }
    }
}
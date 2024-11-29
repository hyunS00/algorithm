#include <iostream>
#include <vector>
#define MAXLEN 2000
#define endl "\n"

using namespace std;

int N, M, ans;
vector<vector<int>> adj(MAXLEN, vector<int>());
int visited[MAXLEN];
bool found = false;

void dfs(int cnt, int pos) {
    if(found) return;
    if(cnt == 4){
        ans = 1;
        found = true;
        return;
    }
    
    for(auto &next : adj[pos]){
        if(!visited[next]){
            visited[next] = 1;
            dfs(cnt + 1, next);
            visited[next] = 0;
            if(found) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < N && !found; i++){
        visited[i] = 1;
        dfs(0, i);
        visited[i] = 0;
    }
    
    cout << ans << endl;
}

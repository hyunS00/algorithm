#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int n, m;
ll ans;
int board[10][10];
int visited[10];

void func(int d, int c, ll w){
    if(d == n){
        if(board[c][0] != 0){
            ans = max(ans, w+board[c][0]);
        }
        return;
    }
    if(visited[c]) return;
    visited[c] = 1;
    for(int i = 1; i <= n; i++){
        if(visited[i] || board[c][i] == 0) continue;
        func(d+1, i, w + board[c][i]);
    }
    visited[c] = 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v, d;
        cin >> u >> v >> d;
        board[u][v] = max(board[u][v], d);
    }

    func(0, 0, 0);
    if(ans == 0) ans = -1;
    cout << ans;
}
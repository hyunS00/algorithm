#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int board[1001][1001];
int dp[2][1001][1001];
int visited[2][1001][1001];

int upper(int x, int y){
    if(x == n-1 && y == 0) return board[x][y];
    if(visited[0][x][y]) return dp[0][x][y];
    visited[0][x][y] = 1;
    dp[0][x][y] = -1e9; 
    if(x < n)
        dp[0][x][y] = max(dp[0][x][y], upper(x+1, y)+board[x][y]);
    if(y > 0)
        dp[0][x][y] = max(dp[0][x][y], upper(x, y-1)+board[x][y]);
    return dp[0][x][y];
}

int lower(int x, int y){
    if(x == n-1 && y == m-1) return board[x][y];
    if(visited[1][x][y]) return dp[1][x][y];
    visited[1][x][y] = 1;
    dp[1][x][y] = -1e9; 
    if(x < n)
        dp[1][x][y] = max(dp[1][x][y], lower(x+1, y)+board[x][y]);
    if(y < m)
        dp[1][x][y] = max(dp[1][x][y], lower(x, y+1)+board[x][y]);
    return dp[1][x][y];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            cin >> board[x][y];

    int ans = -1e9;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            ans = max(ans, upper(x, y)+lower(x, y));
        }
    }
    cout << ans;
}
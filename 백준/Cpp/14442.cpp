#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, k;
string board[1005];
int dist[1005][1005][15];
queue <tuple<int, int, int>> Q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    Q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while(!Q.empty()){
        int x, y, b;
        tie(x, y, b) = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nb = b;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '1' && b > k) continue;
            if(board[nx][ny] == '1') nb++;
            if(dist[nx][ny][nb]) continue;
            dist[nx][ny][nb] = dist[x][y][b] + 1;
            Q.push({nx, ny, nb});
        }
    }

    int ans = 1000000;
    for(int i = 0; i <= k; i++){
        if(dist[n-1][m-1][i])
            ans = min(ans, dist[n-1][m-1][i]);
    }

    if(ans == 1000000) ans = -1;
    cout << ans;
}
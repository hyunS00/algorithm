#include<iostream>
using namespace std;

int n, m, x, y, p;
int board[51][51];
int visited[51][51];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int dd[4] = {0, 1, 1, 0};

int func(int x, int y, int d, int pipe){
    if(pipe == 0) return 0;

    int mx = 0;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int nd = dd[dir];
        int np = pipe-1;
        if(d != nd) np = pipe-2;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited[nx][ny] || np < 0) continue;
        visited[nx][ny] = true;
        mx = max(mx, board[nx][ny] + func(nx, ny, nd, np));
        visited[nx][ny] = false;
    }
    return mx;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    cin >> x >> y >> p;
    int ans = 0;
    visited[x][y] = true;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(p-1 < 0) continue;
        visited[nx][ny] = true;
        ans = max(ans, board[nx][ny] + func(nx, ny, dd[dir], p-1));
        visited[nx][ny] = false;
    }
    ans += board[x][y];
    cout << ans;
}
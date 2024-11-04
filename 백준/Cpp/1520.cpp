#include<iostream>
using namespace std;

int n, m;
int board[505][505];
int dist[505][505];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int func(int y, int x){
    if(dist[y][x] >= 0)
        return dist[y][x];

    if(dist[y][x] == -1)
        dist[y][x] = 0;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(board[y][x] >= board[ny][nx]) continue;
        dist[y][x] += func(ny, nx);
    }

    return  dist[y][x];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int y = 0; y < n; y++)
        for(int x = 0; x < m; x++)
            cin >> board[y][x];

    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i]+m, -1);
    dist[0][0] = 1;
    cout << func(n-1, m-1);
}   
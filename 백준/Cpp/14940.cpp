#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m;
int board[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> Q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin >> board[x][y];
            if(board[x][y] == 2) Q.push({x, y});
            else if(board[x][y] == 1) dist[x][y] = -1;
        }
    }

    while(!Q.empty()){
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 1 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }

    for(int x = 0 ; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << dist[x][y] << " ";
        }
        cout << endl;
    }
}
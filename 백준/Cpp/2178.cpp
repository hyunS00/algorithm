#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100
#define X first
#define Y second
#define endl "\n"

using namespace std;

string board[MAX];
int dist[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int x = 0; x < n; x++) fill(dist[x], dist[x]+m, -1);

    for(int x = 0; x < n; x++){
        cin >> board[x];
    }

    queue<pair<int, int> > Q;
    dist[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        int x = cur.X;
        int y = cur.Y;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '0' || dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }

    cout << dist[n-1][m-1] << endl;
}
#include<iostream>
#include<queue>
#include<algorithm>
#define X first
#define Y second
using namespace std;

int n, m, ans;
string board[50];
queue<pair<int,int>> Q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int x = 0; x < n; x++)
        cin >> board[x];

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(board[x][y] == 'W') continue;
            int dist[50][50];
            for(int x = 0; x < n; x++)
                fill(dist[x], dist[x]+m, -1);
            dist[x][y] = 0;
            Q.push({x, y});
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(dist[nx][ny] >= 0 || board[nx][ny] == 'W') continue;
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                    ans = max(ans, dist[nx][ny]);
                }
            }
        }
    }

    cout << ans;
}
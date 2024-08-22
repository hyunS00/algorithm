#include<iostream>
#include<queue>
#define MAX 100
#define X first
#define Y second

using namespace std;

int board[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue <pair<int, int> > Q;

int n, ans = MAX*2;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int x = 0; x < n; x++){
        for(int y = 0 ; y < n; y++){
            cin >> board[x][y];
        }
    }

    for(int x = 0; x < n; x++){
        for(int y = 0 ; y < n; y++){
            if(visited[x][y]) continue;

            if(board[x][y]){
                Q.push({x, y});
                visited[x][y] = true;
                
                queue<pair<int, int> > Q2;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();

                    for(int dir = 0 ; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                        if(visited[nx][ny]) continue;
                        visited[nx][ny] = true;

                        if(board[nx][ny]) Q.push({nx, ny});
                        else Q2.push({nx, ny});
                    }
                }

                int dist[MAX][MAX];
                for(int i = 0; i < n; i++) fill(dist[i], dist[i] + n, 0);

                while (!Q2.empty())
                {
                    pair<int, int> cur = Q2.front(); Q2.pop();

                    for(int dir = 0 ; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                        if(dist[nx][ny] > 0 || visited[nx][ny]) continue;

                        if(board[nx][ny]){
                            ans = min(ans, dist[cur.X][cur.Y]+1);

                            while(!Q2.empty()) Q2.pop();
                            break;
                        }

                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        Q2.push({nx, ny});
                    }
                }
            }
        }

    }
    cout << ans << endl;
}
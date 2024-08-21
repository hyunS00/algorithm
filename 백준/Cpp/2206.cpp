#include<iostream>
#include<queue>
#include<tuple>

#define MAX 1000
#define X 0
#define Y 1
#define B 2
#define endl "\n"

using namespace std;

int n, m;
queue<tuple<int, int, bool> >Q;

string board[MAX];
int dist[MAX][MAX][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;

    for(int x = 0; x < n; x++){
        cin >> board[x];
    }

    dist[0][0][0] = 1;
    Q.push({0, 0, 0});

    while(!Q.empty()){
        tuple<int, int, bool> cur = Q.front(); Q.pop();

        int x = get<X>(cur);
        int y = get<Y>(cur);
        bool isBroken = get<B>(cur);

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(isBroken){
                if(dist[nx][ny][1] > 0 || board[nx][ny] == '1') continue;

                Q.push({nx, ny, 1});
                dist[nx][ny][1] = dist[x][y][1] + 1;
            }else{
                if(dist[nx][ny][0] > 0) continue;

                if(board[nx][ny] == '0'){
                    Q.push({nx, ny, 0});
                    dist[nx][ny][0] = dist[x][y][0] + 1;
                }
                else{
                    Q.push({nx, ny, 1});
                    dist[nx][ny][1] = dist[x][y][0] + 1;
                }
            }
        }
    }

    if(dist[n-1][m-1][0] == -1 && dist[n-1][m-1][1] == -1) cout << -1 << endl;
    else if(dist[n-1][m-1][0] != -1 && dist[n-1][m-1][1] == -1) cout << dist[n-1][m-1][0] << endl;
    else if (dist[n-1][m-1][0] == -1 && dist[n-1][m-1][1] != -1) cout << dist[n-1][m-1][1] << endl;
    else cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]) << endl;
}
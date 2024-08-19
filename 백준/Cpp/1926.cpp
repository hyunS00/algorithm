#include<iostream>
#include<queue>
#define endl "\n"
#define X first
#define Y second
#define MAXN 501

using namespace std;

int board[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, cnt, max_area;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin >> board[x][y];
        }
    }

    queue< pair<int, int> > Q;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(visited[x][y]) continue;
            visited[x][y] = true;
            if(board[x][y]){
                Q.push({x,y});
                cnt++;
                int area = 1;

                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || nx >= n) continue;
                        if(visited[nx][ny]) continue;
                        visited[nx][ny] = true;
                        if(board[nx][ny]){
                            Q.push({nx, ny});
                            area++;
                        }
                    }
                    max_area = max(max_area, area);
                }
            }
        }
    }

    cout << cnt << endl;
    cout << max_area << endl;
}
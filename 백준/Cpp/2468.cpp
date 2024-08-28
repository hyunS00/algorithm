#include<iostream>
#include<queue>
#define X first
#define Y second
#define endl "\n"
#define MAX 101
using namespace std;

int board[MAX][MAX];
int visited[MAX][MAX];
int n, t;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

queue< pair<int, int> > Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin >> board[x][y];
            t = max(t, board[x][y]);
        }
    }

    int ans = 1;
    for(int h = 1; h < t; h++){
        for(int x = 0; x < n; x++) fill(visited[x], visited[x] + n, 0);
        int area = 0;

        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(visited[x][y] || board[x][y] <= h) continue;
                visited[x][y] = true;

                Q.push({x, y});
                area++;

                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();

                    int x = cur.X;
                    int y = cur.Y;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(visited[nx][ny] || board[nx][ny] <= h) continue;

                        visited[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
                
            }
        }
        ans = max (ans, area);
    }
    cout << ans << endl;
}
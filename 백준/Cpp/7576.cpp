#include<iostream>
#include<queue>
#define X first
#define Y second
#define MAX 1000
#define endl "\n"

using namespace std;

int board[MAX][MAX];
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int> > Q;

    for(int x = 0; x < m; x++){
        for(int y = 0; y < n; y++){
            cin >> board[x][y];
            if(board[x][y] == 1){
                Q.push({x, y});
            }
        }
    }
    int ans = 0;

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        int x = cur.X;
        int y = cur.Y;

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if(board[nx][ny] == 0){
                board[nx][ny] = board[x][y] + 1;
                Q.push({nx, ny});

                ans = max(ans, board[x][y]);
            }
        }

    }

    for(int x = 0; x < m; x++){
        if(ans == -1) break;
        for(int y = 0; y < n; y++){
            if(board[x][y] == 0) ans = -1;
        }
    }

    cout << ans << endl;
}
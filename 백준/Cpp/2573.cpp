#include<iostream>
#include<queue>
#define MAX 300
#define endl "\n"
#define X first
#define Y second

using namespace std;

int board[MAX][MAX];
int visited[MAX][MAX];

queue< pair<int, int> > Q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;

    cin >> n >> m;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin >> board[x][y];
        }
    }
    int year = 0;
    while(true){
        year++;
        int zero[MAX][MAX] = {0};

        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(board[x][y] > 0){
                     for(int dir = 0; dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny > m) continue;

                        if(board[nx][ny] <= 0){
                            zero[x][y]++;
                        }
                    }
                }
            }
        }

        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                board[x][y] = max(0, board[x][y] - zero[x][y]);
            }
        }

        int x = -1, y = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] > 0){
                    x = i;
                    y = j;
                    cnt++;
                }
            }
        }

        if(cnt == 0){
            cout << 0 << endl;
            return 0;
        }

        for(int i = 0; i < n; i++) fill(visited[i], visited[i] + m, 0);

        visited[x][y] = 1;
        Q.push({x, y});
        int cnt2 = 1;
        while(!Q.empty()){
            pair<int, int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny > m) continue;

                if(visited[nx][ny] || board[nx][ny] <= 0) continue;

                visited[nx][ny] = true;
                Q.push({nx, ny});
                cnt2++;
            }
        }

        if(cnt != cnt2){
            cout << year << endl;
            return 0;
        }
    }
}
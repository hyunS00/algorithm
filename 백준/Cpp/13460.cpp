#include<iostream>
#include<tuple>
#include<queue>
#define X first
#define Y second

using namespace std;

int n, m;
string board[11];
int dist[11][11][11][11];

pair<int, int> red, blue;

// 오른쪽, 위쪽, 왼쪽,  아래쪽
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<tuple<int, int, int, int> >Q;

int bfs(){
    Q.push({red.X, red.Y, blue.X, blue.Y});
    dist[red.X][red.Y][blue.X][blue.Y] = 0;
    
    while (!Q.empty()){
        int rx, ry, bx, by;
        tie(rx, ry, bx, by) = Q.front(); Q.pop();

        int cnt = dist[rx][ry][bx][by];
        
        if(cnt >= 10)
            return -1;

        for(int dir = 0; dir < 4; dir++){
            int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by;
            // 파란구슬 먼저

            while (board[n_bx + dx[dir]][n_by + dy[dir]] == '.'){
                n_bx += dx[dir];
                n_by += dy[dir];
            }

            if(board[n_bx + dx[dir]][n_by + dy[dir]] == 'O')
                continue;
            
            while (board[n_rx + dx[dir]][n_ry + dy[dir]] == '.'){
                n_rx += dx[dir];
                n_ry += dy[dir];
            }
            
            if(board[n_rx + dx[dir]][n_ry + dy[dir]] == 'O')
                return cnt + 1;
            
            if(n_rx == n_bx && n_ry == n_by){
                if(dir == 0){
                    ry < by ? n_ry-- : n_by--;
                }
                else if(dir == 1){
                    rx < bx ? n_rx-- : n_bx--;
                }
                else if(dir == 2){
                    ry > by ? n_ry++: n_by++;
                }
                else{
                    rx > bx ? n_rx++ : n_bx++;
                }
            }

            if(dist[n_rx][n_ry][n_bx][n_by] > 0)
                continue;

            dist[n_rx][n_ry][n_bx][n_by] = cnt + 1;
            Q.push({n_rx, n_ry, n_bx, n_by});
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int x = 0; x < n; x++){
        cin >> board[x];
        
        for(int y = 0; y < m; y++){
            if(board[x][y] == 'R'){
                red = {x, y};
                board[x][y] = '.';
            }
            else if(board[x][y] == 'B'){
                blue = {x, y};
                board[x][y] = '.';
            }
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                fill(dist[i][j][k], dist[i][j][k] + m, -1);
                
    
    cout << bfs() << endl;
}
    
#include<iostream>
#include<queue>
#include<tuple>
#define MAX 1001
#define X 0
#define Y 1
#define M 2
#define endl "\n"

using namespace std;

int r,c;
char board[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, char> > Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> r >> c;

    int jx,jy;
    for(int x = 0; x < r; x++){
        for(int y = 0; y < c; y++){
            cin >> board[x][y];

            if(board[x][y] == 'F'){
                Q.push({x, y, 'F'});
            }else if(board[x][y] == 'J'){
               jx = x;
               jy = y;
            }
        }
    }

    Q.push({jx, jy, 'J'});

    while(!Q.empty()){
        tuple<int, int, char> cur = Q.front(); Q.pop();

        int x = get<X>(cur);
        int y = get<Y>(cur);
        char m = get<M>(cur);

        cout << endl << c << " : " << x << " " << y << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        if(m == 'J'){    
            if(board[x][y] == 'F') continue;

            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                    cout << dist[x][y] + 1 << endl;
                    return 0;
                }

                if(board[nx][ny] == '.'){
                    Q.push({nx, ny, 'J'});
                    board[x][y] = '_';
                    board[nx][ny] = 'J';
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        else {
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

                if(board[nx][ny] == '.'){
                    Q.push({nx, ny, 'F'});
                    board[nx][ny] = 'F';
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
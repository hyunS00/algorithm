#include<iostream>
#define X first
#define Y second
#define endl "\n"

using namespace std;

const int LIMIT = 50;

int n, m, ans;
int board[LIMIT][LIMIT];
bool isClean[LIMIT][LIMIT];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int x, y, dir;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y >> dir;
    dir = 4 - dir;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin >> board[x][y];
        }
    }

    while (true){
        if(!isClean[x][y]){
            isClean[x][y] = true;
            ans++;
        }

        bool isNotClean = false;
        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(isClean[nx][ny] || board[nx][ny] == 1) continue;
            isNotClean = true;
            break;
        }

        if(isNotClean){
            dir = (dir + 1) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!isClean[nx][ny] && board[nx][ny] == 0){
                x = nx;
                y = ny;
            }
        }
        else{
            int ret = (dir+2) % 4;
            int nx = x + dx[ret];
            int ny = y + dy[ret];
            if(board[nx][ny] == 1) break;
            x = nx;
            y = ny;
        }
    }
    
    cout << ans << endl;
}
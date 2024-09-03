#include<iostream>
#define endl "\n"
using namespace std;

int board[20][20];

int dx[4] = {0, 1,  1, -1};
int dy[4] = {1, 0,  1, 1};

bool check(int x, int y);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(int x = 1; x <= 19; x++){
        for(int y = 1; y <= 19; y++){
            cin >> board[x][y];
        }
    }

    for(int x = 1; x <=19; x++){
        for(int y = 1; y <=19; y++){
            if(board[x][y] > 0 && check(x, y)){
                cout << board[x][y] << endl;
                cout << x << " " << y <<endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
}

bool check(int x, int y){
    int color = board[x][y];

    for(int dir = 0; dir < 4; dir++){
        int cnt = 1;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while(nx >= 1 && nx <= 19 && ny >= 1 && ny <= 19 && board[nx][ny] == color){
            nx += dx[dir];
            ny += dy[dir];
            cnt++;
        }
        if( cnt != 5) continue;
        
        nx = x - dx[dir];
        ny = y - dy[dir];
        while(nx >= 1 && nx <= 19 && ny >= 1 && ny <= 19 && board[nx][ny] == color){
            nx -= dx[dir];
            ny -= dy[dir];
            cnt++;
        }

        if(cnt == 5) return true;
    }
    return false;
}
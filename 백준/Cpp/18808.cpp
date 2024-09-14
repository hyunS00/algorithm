#include<iostream>

using namespace std;

const int LIMIT = 40;

int n, m, k, ans;
int board[LIMIT][LIMIT];
int sticker[4][LIMIT][LIMIT];

bool masking(int dir,int r, int c);
bool check(int dir, int x, int y, int r, int c);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    while (k--)
    {
        int r, c;
        cin >> r >> c;


        for(int x = 0; x < r; x++){
            for(int y = 0; y < c; y++){
                cin >> sticker[0][x][y];
            }
        }

        for(int dir = 0; dir < 4; dir++){
            if(dir%2==0 && masking(dir, r, c))
                break;
            if(dir%2==1 && masking(dir, c, r))
                break;
        }
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(board[x][y]) ans++;
        }
    }

    cout << ans << endl;
}

bool masking(int dir,int r, int c){
    int criteria = c-1;

    if(dir >= 1){
        for(int x = 0; x < r; x++){
            for(int y = 0; y < c; y++){
                sticker[dir][x][y] = sticker[dir-1][criteria - y][x];
            }
        }
    }

    for(int x = 0; x <= n - r; x++){
        for(int y = 0; y <= m - c; y++){
            if(check(dir, x, y, r, c))
                return true;
        }
    }
    return false;
}

bool check(int dir, int x, int y, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[dir][i][j] && board[x + i][y + j])
                return false;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[dir][i][j]) board[x + i][y + j] = sticker[dir][i][j];
        }
    }
    return true;
}
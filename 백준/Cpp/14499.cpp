#include<iostream>
#define endl "\n"

using namespace std;

const int LIMIT = 20;

int n, m, x, y, k;
int board[LIMIT][LIMIT];

int dice[6];

const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, 1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y >> k;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin >> board[x][y];
        }
    }

    while (k--)
    {
        int com;
        cin >> com;
        int nx = x + dx[com];
        int ny = y + dy[com];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        x = nx;
        y = ny;

        if(com == 1){
            int tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[2];
            dice[2] = dice[5];
            dice[5] = tmp;
        }
        else if(com == 2){
            int tmp = dice[0];
            dice[0] = dice[5];
            dice[5] = dice[2];
            dice[2] = dice[4];
            dice[4] = tmp;
        }
        else if(com == 3){
            int tmp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[2];
            dice[2] = dice[1];
            dice[1] = tmp; 
        }
        else if(com == 4){
            int tmp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = tmp;  
        }
        if(board[x][y] > 0){
            dice[0] = board[x][y];
            board[x][y] = 0;
        }
        else{
            board[x][y] = dice[0];
        }

        cout << dice[2] << endl;
    }
}
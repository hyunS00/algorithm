#include<iostream>
using namespace std;

int n, m, r;
int board[100][100];

void rot(int dir){
    int tmp[100][100];
    if(dir == 3)
        for(int x = 0; x < n; x++)
            for(int y = 0; y < m; y++)
                tmp[y][n-1-x] = board[x][y];
    else
        for(int x = 0; x < n; x++)
            for(int y = 0; y < m; y++)
                tmp[m-y-1][x] = board[x][y];
    swap(n, m);
    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            board[x][y] = tmp[x][y];
}

void flip(int dir){
    int tmp[100][100];
    if(dir == 1)
        for(int x = 0; x < n; x++)
            for(int y = 0; y < m; y++)
                tmp[n-x-1][y] = board[x][y];
    else 
        for(int x = 0; x < n; x++)
            for(int y = 0; y < m; y++)
                tmp[x][m-y-1] = board[x][y];

    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            board[x][y] = tmp[x][y];
}

void grid(int dir){
    int tmp[100][100];
    int mx = n/2;
    int my = m/2;
    if(dir == 5){
        for(int x = 0; x < mx; x++)
            for(int y = 0; y < my; y++)
                tmp[x][my+y] = board[x][y];
        for(int x = 0; x < mx; x++)
            for(int y = my; y < m; y++)
                tmp[mx+x][y] = board[x][y];
        for(int x = mx; x < n; x++)
            for(int y = my; y < m; y++)
                tmp[x][y-my] = board[x][y];
        for(int x = mx; x < n; x++)
            for(int y = 0; y < my; y++)
                tmp[x-mx][y] = board[x][y];
    }else{
        for(int x = 0; x < mx; x++)
            for(int y = 0; y < my; y++)
                tmp[x+mx][y] = board[x][y];
        for(int x = mx; x < n; x++)
            for(int y = 0; y < my; y++)
                tmp[x][my+y] = board[x][y];
        for(int x = mx; x < n; x++)
            for(int y = my; y < m; y++)
                tmp[x-mx][y] = board[x][y];
        for(int x = 0; x < mx; x++)
            for(int y = my; y < m; y++)
                tmp[x][y-my] = board[x][y];
    }

    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            board[x][y] = tmp[x][y];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r;
    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            cin >> board[x][y];

    for(int i = 0; i < r; i++){
        int a;
        cin >> a;
        switch (a){
        case 1: case 2:
            flip(a);
            break;
        case 3: case 4:
            rot(a);
            break;
        case 5: case 6:
            grid(a);
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
}
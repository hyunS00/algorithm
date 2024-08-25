#include<iostream>
#define endl "\n"
#define MAX 3*(1<<10)
using namespace std;

char board[MAX][MAX*2];
int n;

void solve(int n, int x, int y);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) fill(board[i], board[i] + n * 2 - 1  , ' ');

    solve(n, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << board[i] << endl;
    }
}

void fill_stars(int x, int y){
    board[x][y] = '*';
    board[x+1][y-1] = '*';
    board[x+1][y+1] = '*';
    for(int i = y-2; i <= y+2; i++)
        board[x+2][i] = '*';
}

void solve(int n, int x, int y){
    if(n == 3){
        fill_stars(x, y);
        return;
    }
    
    int ns = n / 2;
    solve(ns, x, y);
    solve(ns, x+ns, y - ns);
    solve(ns, x+ns, y +ns);
}
#include<iostream>
#define endl "\n"

using namespace std;

const int MAX = 64;

string board[MAX];
int n;

bool check(int x, int y, int n);
void solve(int x, int y, int n);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> board[i];

    solve(0, 0, n);
}

bool check(int x, int y, int n){
    for(int i = x; i < x + n; i++)
    for(int j = y; j < y + n; j++)
        if(board[x][y] != board[i][j])
            return false;
    return true;
}

void solve(int x, int y, int n){
    if(check(x, y, n)){
        cout << board[x][y];
        return;
    }
    cout << "(";
    int num = n/2;
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
        solve(x + num * i, y + num * j, num);
    cout << ")";
}
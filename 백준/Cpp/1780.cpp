#include<iostream>
#define endl "\n"
#define MAX 3*3*3*3*3*3*3

using namespace std;

int board[MAX][MAX];
int cnt[3];
int n;

void func(int n, int x, int y);
bool check(int n, int x, int y);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    func(n, 0, 0);

    for(int i = 0; i < 3; i++){
        cout << cnt[i] << endl;
    }
}

bool check(int n, int x, int y){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}

void func(int n, int x, int y){
    if(check(n, x, y)){
        cnt[board[x][y]+1]++;
        return;
    }

    int num = n / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            func(num, x + num * i, y + num * j);
        }
    }
}
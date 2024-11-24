#include<iostream>
using namespace std;

int n, ans[2];
int board[10][10];
int isUsed1[20];
int isUsed2[20];

void func(int x, int y, int k, int color) {
    if(y >= n){
        x++;
        if(y%2 == 0) y = 1;
        else y = 0;
    }
    if(x >= n){
        ans[color] = max(ans[color], k);
        return;
    }
    if(board[x][y] && !isUsed1[x+y] && !isUsed2[n+1+x-y]){
        isUsed1[x+y] = 1;
        isUsed2[n+1+x-y] = 1;
        func(x, y+2, k+1, color);
        isUsed1[x+y] = 0;
        isUsed2[n+1+x-y] = 0;
    }
    func(x, y+2, k, color);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin >> board[x][y];
        }
    }
    func(0, 0, 0, 0);
    func(0, 1, 0, 1);
    cout << ans[0]+ans[1];
}
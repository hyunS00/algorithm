#include<iostream>
using namespace std;

int n;
int board[64][64];
int dp[64][64];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    dp[0][0] = 1;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(!dp[x][y]) continue;

            int nx = x + board[x][y];
            int ny = y + board[x][y];

            if(nx < n){
                dp[nx][y] = 1;
            }

            if(ny < n){
                dp[x][ny] = 1;
            }
        }
    }

    if(dp[n-1][n-1]) cout << "HaruHaru";
    else cout << "Hing";
}
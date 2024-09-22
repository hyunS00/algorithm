#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int board[1001][1001];
int dp[1001][1001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int x = 1; x <= n; x++){
        string s;
        cin >> s;
        for(int y = 1; y <= m; y++)
            board[x][y] = s[y-1] - '0';
    }
    
    int ans = 0;
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= m; y++){
            if(board[x][y]){
                dp[x][y] = min({dp[x-1][y], dp[x][y-1], dp[x-1][y-1]}) + 1;
                ans = max(ans, dp[x][y] * dp[x][y]);
            }
        }
    }

    cout << ans << endl;
}
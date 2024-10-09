#include<iostream>
#define endl "\n"
using namespace std;

int t;
int dp[1010][1010];
const int mod = 1000000009;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;
    for(int i = 4; i <= 1000; i++){
        for(int j = 2; j <= 1000; j++){
            for(int k = 1; k <= 3; k++){
                dp[i][j] = (dp[i][j]+dp[i-k][j-1]) % mod;
            }
        }
    }
    
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
}
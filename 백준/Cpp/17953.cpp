#include<iostream>
using namespace std;

int n, m;
int v[12][100002];
int dp[12][100002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 1; i <= m; i++)
        dp[i][1] = v[i][1];

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= m; k++){
                if(j == k){
                    dp[k][i+1] = max(dp[k][i+1], dp[j][i] + v[k][i+1]/2);
                }
                else{
                    dp[k][i+1] = max(dp[k][i+1], dp[j][i] + v[k][i+1]);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = max(ans, dp[i][n]);
    }

    cout << ans;
}
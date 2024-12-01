#include<iostream>
#define MAXLEN 10000
#define endl "\n"

using namespace std;

int n;
int wine[MAXLEN + 1];
int dp[MAXLEN + 1][3];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> wine[i];
    }
    dp[1][1] = dp[1][2] = wine[1];

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 2; j++)
            dp[i][0] = max(dp[i][0], dp[i-1][j]);
        dp[i][1] = dp[i-1][0] + wine[i];
        dp[i][2] = dp[i-1][1] + wine[i];
    }

    int ans = 0;
    for(int j = 0; j <= 2; j++)
        ans = max(ans, dp[n][j]);

    cout << ans << endl;
}
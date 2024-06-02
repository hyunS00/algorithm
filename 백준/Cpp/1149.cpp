#include<iostream>
#define MAXLEN 1000
#define endl "\n";

using namespace std;

int N;
int rgb[MAXLEN + 1][3];
int dp[MAXLEN + 1][3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    
    dp[1][0] = rgb[1][0];
    dp[1][1] = rgb[1][1];
    dp[1][2] = rgb[1][2];

    for(int i = 1; i <= N; i++){
        dp[i][0] = min(dp[i-1][1] + rgb[i][0], dp[i-1][2] + rgb[i][0]);
        dp[i][1] = min(dp[i-1][0] + rgb[i][1], dp[i-1][2] + rgb[i][1]);
        dp[i][2] = min(dp[i-1][0] + rgb[i][2], dp[i-1][1] + rgb[i][2]);
    }

    int ans = min(min(dp[N][0],dp[N][1]),dp[N][2]);

    cout << ans << endl;
}
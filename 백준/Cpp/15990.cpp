#include<iostream>
#define endl "\n"

using namespace std;

typedef long long ll;

const int mod = 1000000009;
const int MAXN = 100000;

int T, n;
ll dp[MAXN+1][4];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(ll i = 4; i <= MAXN; i++){
        if(i - 1 >= 0)
            dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
        if(i - 2 >= 0)
            dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
        if(i - 3 >= 0)
            dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % mod;
    }
    
    while (T--)
    {
        cin >> n;
        ll ans = (dp[n][1] + dp[n][2] + dp[n][3]) % mod;
        cout << ans << endl;
    }   
}
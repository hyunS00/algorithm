#include<iostream>
#define MAXLEN 1000000
#define mod 1000000009

using namespace std;

typedef long long ll;

int T, n;
ll dp[MAXLEN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;


    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= MAXLEN; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
    }

    while (T--)
    {
        cin >> n;

        cout << dp[n] << endl;
    }
    
}
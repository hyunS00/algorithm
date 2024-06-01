#include<iostream>
using namespace std;

typedef long long ll;

const int mod = 1000000000;
const int MAXLEN = 100;

int N;
ll dp[MAXLEN +1][10];

int main(){
    cin >> N;
    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++){
        dp[i][0] = dp[i-1][1];
        for(int j = 1; j <= 8; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
        dp[i][9] = dp[i-1][8];
    }

    ll sum = 0;
    for(int i = 0; i <= 9; i++){
        sum += dp[N][i];
    }

    sum %= mod;
    cout << sum << "\n";
}
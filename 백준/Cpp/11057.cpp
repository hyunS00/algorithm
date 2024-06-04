#include<iostream>
#define MAXLEN 1000
#define mod 10007
#define endl "\n";

using namespace std;

typedef long long ll;

int N;
ll dp[MAXLEN + 1][10];

int main(){
    cin >> N;
    for(int i = 0; i <= 9; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i++){
        dp[i][0] = dp[i-1][0];
        for(int j = 1; j <= 9; j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
        }
    }

    ll sum = 0;
    for(int i = 0; i <= 9; i++){
        sum += dp[N][i];
    }

    cout << sum % mod << endl;
}
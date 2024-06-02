#include<iostream>
#define MAXLEN 100000
#define mod 9901
#define endl "\n"

using namespace std;

typedef long long ll;

int N;
ll dp[MAXLEN + 1][3];

int main(){
    cin >> N;
    dp[1][0] = 1; // 0 0
    dp[1][1] = 1; // 1 0
    dp[1][2] = 1; // 0 1

    for(int i = 2; i <= MAXLEN; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][0]) % mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][0]) % mod;
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod;
    }

    cout << (dp[N][0] + dp[N][1] +dp[N][2]) % mod << endl;
}
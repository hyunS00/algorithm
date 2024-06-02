#include<iostream>
#define MAXLEN 90
#define endl "\n"

using namespace std;

typedef long long ll;

ll N;
ll dp[MAXLEN+1][2];

int main(){
    cin >> N;
    dp[1][1] = 1;

    for(int i = 2; i <= MAXLEN; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[N][0] + dp[N][1] << endl;
}
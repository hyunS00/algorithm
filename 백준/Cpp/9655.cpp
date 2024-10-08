#include<iostream>

using namespace std;

int n;
int dp[10001][2];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    dp[0][0] = 0;
    dp[0][1] = 1;

    for(int i = 1; i <= n; i++){
        if(dp[i-1][0] == 0) dp[i][0] = 1;
        if(dp[i-1][1] == 0) dp[i][1] = 1;
    }

    if(dp[n][0]){
        cout << "SK" << endl;
    }
    else{
        cout << "CY" << endl;
    }
}
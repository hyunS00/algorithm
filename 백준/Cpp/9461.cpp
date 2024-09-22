#include<iostream>
#define endl "\n"

using namespace std;
typedef long long ll;
int t;
ll dp[101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= 100; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }

    cin >>t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}
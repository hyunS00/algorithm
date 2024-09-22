#include<iostream>
#define endl "\n"

using namespace std;

int n, m;
int dp[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> dp[i];
        dp[i] += dp[i-1];
    }
    while (m--)
    {
        int i, j;
        cin >> i >> j;

        cout << dp[j] - dp[i-1] << endl;
    }
    
}
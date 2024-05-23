#include<iostream>
#include<vector>
using namespace std;

int n, ans;
vector<int> dp(1000001);

int solved(int n);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    ans = solved(n);

    cout << ans << "\n";
}

int solved(int n){
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <=n; i++){
        dp[i] = dp[i-1] +1;
        if(i % 3 == 0)
            dp[i] = min(dp[i], dp[i/3]+1);
        if(i % 2 == 0)
            dp[i] = min(dp[i], dp[i/2]+1);
    }
    return dp[n];
}
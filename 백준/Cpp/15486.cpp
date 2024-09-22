#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int n;
int t[1500001];
int p[1500001];
int dp[1500001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    for (int i = n; i >= 1; i--) {
        if(t[i] + i <= n + 1){
            dp[i] = max(dp[i + t[i]] + p[i], dp[i+1]);
        }
        else{
            dp[i] = dp[i+1];
        }
    }

    cout << *max_element(dp, dp+n+1) << endl;
}
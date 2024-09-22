#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int n;
int dp[100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> dp[i];
    
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i], dp[i-1]+dp[i]);
    }

    cout << *max_element(dp, dp+n) << endl;
}
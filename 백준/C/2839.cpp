#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int dp[5001] ={0,};
    dp[3]=dp[5]=1;
    for(int i=6;i<=N;i++){
        if(dp[i-3]){
            dp[i] = dp[i-3] +1;
        }
        if(dp[i-5]){
            dp[i] = dp[i-5]+1;
        }
    }
    if(dp[N]!=0){
        cout << dp[N] << endl;
    }else{
        cout << -1 << endl;
    }
}
#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> P(10001);
vector<int> dp(10001);

int main(){
    cin >> N;

    for(int i = 1; i<= N; i++){
        cin >> P[i];
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i-j] + P[j]);
        }
    }

    cout << dp[N] << "\n";
}
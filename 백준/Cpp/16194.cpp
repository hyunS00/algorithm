#include<iostream>
#include<vector>
using namespace std;

#define MAX 10000001
#define endl "\n";

int N;
vector<int> P;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    P.resize(N+1);
    dp.resize(N+1, MAX);
    dp[0] = 0;

    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = min(dp[i], P[j] + dp[i-j]);
        }
    }

    cout << dp[N] << endl;
}
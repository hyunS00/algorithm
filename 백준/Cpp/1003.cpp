#include<iostream>
#include<vector>
using namespace std;

pair<int, int> fibonacci(int n, vector<pair<int, int> > &dp);


int main(){
    int T, N;
    cin >> T;
    vector<pair<int, int> > dp(41, {0, 0});
    while (T--)
    {
        cin >> N;

        dp.resize(N+1);
        dp[0] = {1, 0};
        dp[1] = {0, 1};

        pair<int, int> result = fibonacci(N, dp);

        cout << result.first << " " << result.second << "\n";
    }
    
}

pair<int, int> fibonacci(int n, vector<pair<int, int> > &dp){
    if ( n == 0 || n == 1)
        return dp[n];

    if (dp[n].first != 0 || dp[n].second != 0)
        return dp[n];

    pair<int, int> fibo1 = fibonacci(n-1, dp);
    pair<int, int> fibo2 = fibonacci(n-2, dp);

    dp[n] = {fibo1.first + fibo2.first, fibo1.second + fibo2.second};
    return dp[n];
}
#include<iostream>
#define endl "\n"

using namespace std;
const int MAX = 1000;

int n;
int dp[MAX][2];
int arr[MAX][2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    for(int i = 1; i < n; i++){
        dp[i][0] = arr[i][0] + max(dp[i-1][0] + abs(arr[i-1][1] - arr[i][1]), dp[i-1][1] + abs(arr[i-1][0] - arr[i][1]));
        dp[i][1] = arr[i][1] + max(dp[i-1][0] + abs(arr[i-1][1] - arr[i][0]), dp[i-1][1] + abs(arr[i-1][0] - arr[i][0]));
    }
    cout << max(dp[n-1][0],dp[n-1][1]) << endl;
}
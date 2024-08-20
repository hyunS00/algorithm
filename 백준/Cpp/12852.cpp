#include<iostream>
#define endl "\n"
#define MAX 1000002

using namespace std;

int dp[MAX];
int way[MAX];
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        way[i] = i-1;

        if(i % 2 == 0 && dp[i] > dp[i/2] +1){
            dp[i] = dp[i/2] + 1;
            way[i] = i/2;
        }

        if(i % 3 == 0 && dp[i] > dp[i/3] +1){
            dp[i] = dp[i/3] + 1;
            way[i] = i/3;
        }
    }

    cout << dp[n]<< endl;

    int idx = n;
    while(idx != 0){
        cout << idx << " ";
        idx = way[idx];
    }

    cout << endl;
}
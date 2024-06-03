#include<iostream>
#define MAXLEN 1000
#define endl "\n"

using namespace std;

int N, ans;
int A[MAXLEN + 1];
int dp[MAXLEN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    for(int i = 1; i <= N; i++){
        int max_num = 0;
        for(int j = 1; j <= i; j++){
            if(A[i] > A[j])
                max_num = max(max_num, dp[j]);
        }
        dp[i] = max_num + 1;
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}
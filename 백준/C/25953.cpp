#include <bits/stdc++.h>
using namespace std;

int N,T,M,S,E=0;

int dp[10001][10001];

void display(){
    for(int t=0;t<T+1;t++){
        for(int i=0;i<N;i++){
            cout << dp[t][i] << " : ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> T >> M >> S >> E;

    for(int n=0;n<N;n++){
        dp[0][n] = 1000000007;
    }
    dp[0][S]=0;
    display();
    for(int t=0;t<T;t++){
        for(int i=0;i<N;i++) dp[t+1][i] = dp[t][i];
        display();
        for(int i=0;i<M;i++){
            int s,e,w;
            cin >> s >> e >> w;
            dp[t+1][e] = min(dp[t+1][e],dp[t][s]+w);
            dp[t+1][s] = min(dp[t+1][s],dp[t][e]+w);
            display();
        }
    }

    for(int t=0;t<T;t++){
        for(int i=0;i<M;i++){
            cout << dp[t][i] << " : ";
        }
        cout << endl;
    }

    if(dp[T][E]<1000000007) cout << dp[T][E]<<endl;
    else cout << -1<<endl;

    return 0;
}
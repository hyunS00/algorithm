#include<iostream>
#define MAXLEN 6
#define MAXVAL 10000
#define endl "\n"

using namespace std;

int N, M;

int matrix[MAXLEN][MAXLEN];
int dp[MAXLEN][MAXLEN][3];

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];

            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = matrix[i][j];

            if(j == 0) dp[i][j][0] = MAXVAL;
            if(j == M - 1) dp[i][j][2] = MAXVAL;
        }
    }

    for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
            if(j != 0)
                dp[i][j][0] += min(dp[i-1][j-1][1], dp[i-1][j-1][2]);
            
            dp[i][j][1] += min(dp[i-1][j][0], dp[i-1][j][2]);

            if(j != M-1)
                dp[i][j][2] += min(dp[i-1][j+1][0], dp[i-1][j+1][1]);
		}
	}

    int min_val = MAXVAL;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < 3; j++){
            min_val = min(min_val, dp[N-1][i][j]);
        }
    }

    cout << min_val << endl;
}
#include<iostream>
#include<algorithm>
#define W first
#define C second
#define endl "\n"

using namespace std;

const int MAX = 200;

int dp[MAX];
pair<double, double> diamond[MAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(dp, dp + n, 1);
        for(int i = 0; i < n; i++)
            cin >> diamond[i].W >> diamond[i].C;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(diamond[i].W > diamond[j].W && diamond[i].C < diamond[j].C)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        int ans = *max_element(dp, dp+n);
        cout << ans << endl;
    }
    
}
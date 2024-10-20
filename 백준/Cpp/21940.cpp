#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, k;
int d[205][205];
int c[205];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(d[i]+1, d[i]+1+n, INF);
        d[i][i] = 0;
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> c[i];

    for(int l = 1; l <= n; l++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][l] + d[l][j]);
            }
        }
    }

    int mn = INF;
    vector<int> vc;
    for(int i = 1; i <= n; i++){
        int mx = 0;
        for(int j = 0; j < k; j++)
            mx = max(mx, d[i][c[j]] + d[c[j]][i]);

        if(mx < mn){
            mn = mx;
            vc.clear();
            vc.push_back(i);
        }
        else if(mx == mn){
            vc.push_back(i);
        }
    }

    for(int i : vc)
        cout << i << " ";
}
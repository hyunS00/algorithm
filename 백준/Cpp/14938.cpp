#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, r, t;
int d[105][105];
int nxt[105][105];
int item[105];
int a, b, l;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        fill(d[i]+1, d[i]+1+n, INF);
        d[i][i] = 0;
    }

    for(int i = 1; i <= n; i++)
        cin >> item[i];

    while (r--) {
        cin >> a >> b >> l;
        if(l < d[a][b] && l <= m){
            d[a][b] = d[b][a] = l;
            nxt[a][b] = b;
            nxt[b][a] = a;
        }
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int dist = d[i][k] + d[k][j];
                if(dist <= m && dist < d[i][j]){
                    d[i][j] = dist;
                    d[i][j] = dist;
                    nxt[i][j] = nxt[i][k];
                    nxt[j][i] = nxt[j][k];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        vector<int> visited(n+1, 0);
        int mx = 0;
        mx += item[i];
        visited[i] = true;
        for(int j = 1; j <= n; j++){
            if(d[i][j] == 0 || d[i][j] == INF) continue;
            int st = i;
            while(st != j){
                if(!visited[st]){
                    mx += item[st];
                    visited[st] = true;
                }
                st = nxt[st][j];
            }
            if(!visited[j]){
                mx += item[j];
                visited[j] = true;
            }
        }
        ans = max(ans, mx);
    }

    cout << ans;
}
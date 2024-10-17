#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
typedef long long ll;

int n;
vector< tuple<int, int, int> > edge;
int p[1005];

int find(int x){
    if(p[x] == 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    else if( u < v) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int c;
            cin >> c;
            if(i == j) continue;

            edge.push_back({c, i, j});
        }
    }

    sort(edge.begin(), edge.end());
    
    ll ans = 0;
    int cnt = 0;
    for(int i = 0; i < edge.size(); i++){
        int c, a, b;
        tie(c, a, b) = edge[i];

        if(!is_diff_group(a, b)) continue;
        ans += c;
        cnt++;
        if(cnt == n-1) break;
    }

    cout << ans;
}
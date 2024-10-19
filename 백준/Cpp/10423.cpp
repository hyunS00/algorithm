#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

int n, m, k;
tuple<int, int, int> edge[100005];

int p[1005];
int find_set(int x){
    if(p[x] == 0) return x;
    return p[x] = find_set(p[x]);
}

bool is_diff_group(int u, int v){
    u = find_set(u);
    v = find_set(v);

    if(u == v) return 0;
    if(u < v) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        p[c] = -1;
    }

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {w, u , v};
    }
    
    sort(edge, edge+m);
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < m && cnt != n-k; i++){
        int w, u, v;
        tie(w, u, v) = edge[i];

        if(!is_diff_group(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n-k) break;
    }

    cout << ans;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;
typedef long long ll;

int n, m;
pair<int, int> gods[1005];
vector< tuple<ll, int, int> > edge;
int p[1005];
int find(int x){
    if(p[x] == 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    else if(a < b) p[b] = a;
    else p[a] = b;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        gods[i] = {x, y};
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(is_diff_group(a, b))
            cnt++;
    }

    for(int i = 1; i <= n; i++){
        int ax, ay;
        tie(ax, ay) = gods[i];
        for(int j = i + 1; j <= n; j++){
            if(find(i) == find(j)) continue;
            int bx, by;
            tie(bx, by) = gods[j];

            int h = ax - bx;
            int w = ay - by;
            ll len = (ll)h * (ll)h + (ll)w * (ll)w;
            edge.push_back({len, i, j});
        }   
    }

    sort(edge.begin(), edge.end());

    double ans = 0.0;
    for(int i = 0; i < edge.size(); i++){
        int a, b;
        ll l;
        tie(l, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += sqrt((double)l);
        cnt++;
        if(cnt == n-1) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}
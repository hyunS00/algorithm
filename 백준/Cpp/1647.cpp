#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;

int n, m;
tuple<int, int, int> edge[1000005];
int p[100005];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b){
    a = find(a);
    b = find(b);

    if( a == b) return 0;
    else if(a < b) p[b] = a;
    else p[a] = b;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        p[i] = i;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    sort(edge, edge + m);

    int u = n;
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(u == 2) break;
        int c, a, b;
        tie(c, a, b) = edge[i];

        if(!is_diff_group(a, b)) continue;
        ans += c;
        u--;
    }

    cout << ans;
}
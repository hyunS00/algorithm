#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector< tuple<int, int, int> > edge;
int parent[301];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    else if(a < b) parent[b] = a;
    else parent[a] = b;
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int w;
        cin >> w;
        edge.push_back({w, i, n+1});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int p;
            cin >> p;
            if(i == j) continue;
            edge.push_back({p, i, j});
        }
    }

    sort(edge.begin(), edge.end());

    for(int i = 1; i <= n; i++)
        parent[i] = i;

    int cnt = 0;
    int ans = 0;
    for(auto t : edge){
        int cost, a, b;
        tie(cost, a, b) = t;
        if(!is_diff_group(a, b)) continue;
        cnt++;
        ans += cost;
        if(cnt == n) break;
    }
    
    cout << ans;
}
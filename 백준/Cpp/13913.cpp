#include<iostream>
#include<queue>
using namespace std;

int n, k;
int dist[100005];
int pre[100005];
queue<int> Q;

void solve(){
    pre[n] = n;
    dist[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nx : {cur + 1, cur -1, cur*2}){
            if(nx < 0 || nx > 100000) continue;
            if(dist[nx] > -1) continue;
            pre[nx] = cur;
            dist[nx] = dist[cur] + 1;
            if(nx == k ) return;
            Q.push(nx);
        }
    }
}

void func(int cur){
    if(pre[cur] == cur) {
        cout << cur << " ";
        return;
    }
    else func(pre[cur]);
    cout << cur << " ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    fill(dist, dist+100001, -1);
    solve();
    cout << dist[k] << endl;
    func(k);
}
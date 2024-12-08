#include<iostream>
#include<unordered_map>
#include<queue>
#define endl "\n"
using namespace std;
typedef long long ll;

ll l;
int n, k;
unordered_map<ll, ll> board;
queue<ll> Q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> l >> n >> k;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        board[a] = 0;
        Q.push(a);
    }

    int cnt = 0;
    while(!Q.empty()){
        ll cur = Q.front(); Q.pop();
        cout << board[cur] << endl;
        if(++cnt >= k) return 0;
        for(ll nxt : {cur+1, cur-1}){
            if(nxt < 0 || nxt > l) continue;
            if(board.find(nxt) != board.end()) continue;
            board[nxt] = board[cur] + 1;
            Q.push(nxt);
        }
    }
}
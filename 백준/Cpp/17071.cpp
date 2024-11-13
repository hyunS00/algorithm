#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

int n, k;
int dist[2][500001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    if(n == k){
        cout << 0;
        return 0;
    }
    dist[0][n] = 1;
    queue<int> Q;
    Q.push(n);
    int move = 1;
    while(!Q.empty()){
        k += move;
        if(k > 500000){
            cout << -1;
            return 0;
        }
        if(dist[move%2][k]){
            cout << move;
            return 0;
        }
        int size = Q.size();
        for(int i = 0; i < size; i++){
            int x = Q.front(); Q.pop();
            for(int nxt : {x-1, x+1, x*2}){
                if(nxt < 0 || nxt > 500000) continue;
                if(nxt == k){
                    cout << move;
                    return 0;
                }
                if(dist[move%2][nxt]) continue;
                dist[move%2][nxt] = 1;
                Q.push(nxt);
            }
        }
        move++;
    }
    cout << -1;
}
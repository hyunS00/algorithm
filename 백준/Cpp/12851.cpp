#include<iostream>
#include<queue>
#define X first
#define Y second
using namespace std;

const int MAX = 100000;

int n, k;
pair<int,int> board[MAX+1];
queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    if(n == k){
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    Q.push(n);
    board[n].second = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for(int x : {cur - 1, cur + 1, cur * 2}){
            if(x < 0 || x > MAX) continue;
            if(board[x].first != 0 && board[x].first != board[cur].first + 1) continue;
            if(board[x].first == board[cur].first+1){
                board[x].second += board[cur].second;
            }
            else{
                board[x].first = board[cur].first+1;
                board[x].second = board[cur].second;
                Q.push(x);
            }
        }
    }

    cout << board[k].first << endl;
    cout << board[k].second << endl;
}
#include<iostream>
#include<queue>
#define MAX 100001
#define endl "\n"

using namespace std;

int n,k;
int board[MAX];
queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    fill(board, board + MAX, -1);
    
    cin >> n >> k;

    board[n] = 0;
    Q.push(n);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();

        if(cur == k) break;

        if(cur - 1 >= 0){
            if(board[cur-1] <= -1){
                board[cur-1] = board[cur]+1;
                Q.push(cur-1);
            }
        }

        if(cur + 1 < MAX){
            if(board[cur+1] <= -1){
                board[cur+1] = board[cur]+1;
                Q.push(cur+1);
            }
        }

        if(cur * 2 < MAX){
            if(board[cur*2] <= -1){
                board[cur*2] = board[cur]+1;
                Q.push(cur*2);
            }
        }
    }

    cout << board[k] << endl;
}
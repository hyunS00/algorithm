#include<iostream>
#include<queue>
#define endl "\n"

using namespace std;

const int MAX = 1000000;

int f, s, g, u, d;
int board[MAX+1];
queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    fill(board, board+f+1, -1);

    board[s] = 0;
    Q.push(s);

    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        if(cur == g){
            cout << board[cur] << endl;
            return 0;
        }
        for(int move : {cur - d, cur + u}){
            if(move <= 0 || move > f) continue;
            if(board[move] >= 0) continue;

             board[move] = board[cur] + 1;
             Q.push(move);
        }
    }

    cout << "use the stairs" << endl;
}
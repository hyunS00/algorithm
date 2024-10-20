#include<iostream>
#include<cmath>
#include<vector>
#define endl "\n"
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, a, b, c;
int board[105][105];
int nxt[105][105];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        fill(board[i], board[i]+n+1, INF);
        board[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(c < board[a][b]){
            board[a][b] = c;
            nxt[a][b] = b;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(board[i][k]+board[k][j] < board[i][j]){
                    board[i][j] = board[i][k]+board[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j] == INF)
                cout << 0 << " ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j] == 0 || board[i][j] == INF){
                cout << 0 << endl;
                continue;
            }
            int s = i;
            vector<int> v;
            while(s != j){
                v.push_back(s);
                s = nxt[s][j];
            }
            v.push_back(j);
            cout << v.size() << " ";
            for(int k : v)
                cout << k << " ";
            cout << endl;
        }
    }
}
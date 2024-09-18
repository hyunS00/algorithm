#include<iostream>

using namespace std;

int n, mn = 4000;
bool isStartTeam[21];
int board[21][21];

void solve(int k, int s){
    if(k >= n/2){
        int start = 0;
        int link = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(isStartTeam[i] == isStartTeam[j]){
                    if(isStartTeam[i]) start += board[i][j];
                    else link += board[i][j];
                }
            }
        }

        mn = min(mn, abs(start - link));
        return;
    }

    for(int i = s; i < n; i++){
        isStartTeam[i] = true;
        solve(k+ 1, i+1);
        isStartTeam[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }

    solve(0, 1);
    cout << mn << endl;
}
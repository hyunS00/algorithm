#include<iostream>
#include<vector>
using namespace std;

int n;

int r, c;
bool board[101][101];

int x, y, d, g;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> x >> y >> d >> g;
        vector<int> V;

        V.push_back(d);
        board[y][x] = true;
        while (g--)
        {
            for(int i = V.size()-1; i >= 0; i--){
                V.push_back((V[i]+1)%4);
            }
        }

        for(int i = 0; i< V.size(); i++){
            if(V[i] == 0) x++;
            else if(V[i] == 1) y--;
            else if(V[i] == 2) x--;
            else if(V[i] == 3) y++;
            board[y][x] = true;
        }

    }

    int cnt = 0;
    for(int y = 0; y < 100; y++){
        for(int x = 0; x < 100; x++){
            if(board[y][x] && board[y+1][x] && board[y][x+1] && board[y+1][x+1])
                cnt++;
        }
    }

    cout << cnt << endl;
}
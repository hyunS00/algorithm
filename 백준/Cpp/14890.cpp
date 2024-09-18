#include<iostream>

using namespace std;

int n, l;
int board[100][100];
bool slope[100];

void rotate(){
    int tmp[100][100];
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            tmp[x][y] = board[n-1-y][x];
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            board[x][y] = tmp[x][y];
        }
    }
}

bool checkRoad(int x) {
    fill(slope, slope+n, n);
    for(int y = 0; y < n-1; y++){
        int dist = board[x][y] - board[x][y+1];
        if(dist == 0) continue;
        else if(dist == 1) {
            for(int i = 1; i <= l; i++){
                if(y+i >= n || board[x][y+1] != board[x][y+i] || slope[y+i]) return false;
                slope[y+i] = true;
            }
        }
        else if(dist == -1) {
            for(int i = 0; i < l; i++){
                if(y-i < 0 || board[x][y] != board[x][y-i] || slope[y-i]) return false;
                slope[y-i] = true;
            }
        }
        else return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin >> board[x][y];
        }
    }

    int cnt = 0;
    for(int dir = 0; dir < 2; dir++){
        for(int x = 0; x < n; x++){
            if(checkRoad(x)) cnt++;
        }
        rotate();
    }
    
    cout << cnt << endl;
    return 0;
}
#include<iostream>
#define endl "\n"

using namespace std;

const int MAX_N = 10;

int n, ans = 3000, v = 0;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

bool check(int x, int y){
    for(int dir = 0; dir < 5; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
        if(visited[nx][ny]) return false;
    }
    return true;
}

void sumCost(int x, int y){
    for(int dir = 0; dir < 5; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        visited[nx][ny] = true;
        v += board[nx][ny];
    }
}

void subCost(int x, int y){
    for(int dir = 0; dir < 5; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        visited[nx][ny] = false;
        v -= board[nx][ny];
    }
}

void func(int sx, int sy, int cnt){
    if(cnt >= 3){
        ans = min(ans, v);
        return;
    }

    for(int x = sx; x < n; x++){
        for(int y = sy; y < n; y++){
            if(check(x, y)){
                sumCost(x, y);
                func(sx, sy, cnt+1);
                subCost(x, y);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin >> board[x][y];
        }
    }

    func(0, 0, 0);

    cout << ans << endl;
}
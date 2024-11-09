#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m, k;
string board[1002];
int dist[1002][1002][12];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
// x y 이동 벽 낮
queue<tuple<int, int, int, int, bool>> Q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> board[i];

    Q.push({0, 0, 1, 0, true});
    while(!Q.empty()){
        int x, y, cnt, w, daytime;
        tie(x, y, cnt, w, daytime) = Q.front(); Q.pop();
        if(x == n-1 && y == m-1){
            cout << cnt;
            return 0;
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nw = w;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '1'){
                nw++;
                if(!daytime){
                    Q.push({x, y, cnt+1, w, !daytime});
                    continue;
                }
            }
            if(nw > k || dist[nx][ny][nw]) continue;
            dist[nx][ny][nw] = 1;
            Q.push({nx, ny, cnt+1, nw, !daytime});
        }
    }
    
    cout << -1;
}
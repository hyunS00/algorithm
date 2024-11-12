#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

int n, m, ans = 1;
vector<pair<int,int>> board[102][102];
int light[102][102];
int visited[102][102];
queue<pair<int, int>> Q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        board[x][y].push_back({a, b});
    }

    visited[1][1] = 1;
    light[1][1] = 1;
    Q.push({1, 1});
    while(!Q.empty()){
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for(auto &[a, b] : board[x][y]){
            if(light[a][b]) continue;
            light[a][b] = 1;
            ans++;
            for(int dir = 0; dir < 4; dir++){
                int nx = a + dx[dir];
                int ny = b + dy[dir];
                if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
                if(!visited[nx][ny]) continue;
                visited[a][b] = 1;
                Q.push({a, b});
                break;
            }
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            if(visited[nx][ny] || !light[nx][ny]) continue;
            visited[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    

    cout << ans;
}
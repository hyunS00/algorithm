#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
string board[105];
int d[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> board[i];
        board[i] = " " + board[i];
        fill(d[i], d[i]+1+m, INF);
    }

    d[1][1] = 0;
    pq.push({d[1][1], 1, 1});

    while (!pq.empty()){
        int cost, x, y;
        tie(cost, x, y) = pq.top(); pq.pop();
        if(cost != d[x][y]) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            int wall = board[nx][ny] - '0';
            if(d[nx][ny] <= d[x][y]+wall) continue;
            d[nx][ny] = d[x][y]+wall;
            pq.push({d[nx][ny], nx, ny});
        }
    }
    cout << d[n][m];
}
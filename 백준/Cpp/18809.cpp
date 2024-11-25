#include<iostream>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;

int n, m, g, r, ans;
int board[50][50];
vector<pair<int,int>> solution;
int isGreen[250];
vector<int> pick;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(){
    queue<pair<int, int>> Q;
    pair<int,int> dist[50][50];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dist[i][j] = { -1, 0 };
        }
    }
    for(int i = 0; i < pick.size(); i++){
        auto cur = solution[pick[i]];
        if(isGreen[i]) dist[cur.X][cur.Y] = {0, 1};
        else dist[cur.X][cur.Y] = {0, 2};
        Q.push(cur);
    }
    int cnt = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(dist[cur.X][cur.Y].Y == 3) continue;
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == 0 || dist[nx][ny].Y == 3) continue;
            int time = dist[nx][ny].X;
            int color = dist[nx][ny].Y;
            if(color == dist[cur.X][cur.Y].Y) continue;
            if(dist[nx][ny].X == -1){
                dist[nx][ny] = {dist[cur.X][cur.Y].X + 1, dist[cur.X][cur.Y].Y};
                Q.push({nx, ny});
            }
            else if(color && time == dist[cur.X][cur.Y].X+1){
                dist[nx][ny] = {time, 3};
                cnt++;
            }
        }
    }
    
    ans = max(ans, cnt);
}

void func(int start, int greenCount){
    if(pick.size() == g + r){
        if(greenCount == g){
            bfs();
        }
        return;
    }
    
    for(int i = start; i < solution.size(); i++){
        // 현재 위치를 녹색으로 선택
        if(greenCount < g){
            isGreen[pick.size()] = 1;
            pick.push_back(i);
            func(i + 1, greenCount + 1);
            pick.pop_back();
            isGreen[pick.size()] = 0;
        }
        // 현재 위치를 빨간색으로 선택
        if((g + r - pick.size()) > (g - greenCount)){
            isGreen[pick.size()] = 0;
            pick.push_back(i);
            func(i + 1, greenCount);
            pick.pop_back();
            isGreen[pick.size()] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> g >> r;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cin >> board[x][y];
            if(board[x][y] == 2)
                solution.push_back({x, y});
        }
    }

    func(0,0);
    cout << ans;
}
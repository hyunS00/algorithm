#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int n, m, p;
string board[1002];
// num 이동 횟수
pair<int, int> dist[1002][1002];
int s[10], ans[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
        cin >> s[i];

    // num, x, y
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> board[i];
        for(int j = 0; j < m; j++){
            if(board[i][j]-'0' > 0){
                dist[i][j] = {board[i][j]-'0', 0};
                v.push_back({dist[i][j].first, i, j});
            }
        }
    }

    sort(v.begin(), v.end());
    queue<tuple<int, int, int>> Q1;
    for(auto t : v)
        Q1.push(t);

    while(!Q1.empty()){
        int num, x, y;
        tie(num, x, y) = Q1.front(); Q1.pop();

        queue<tuple<int, int, int>>Q2;
        Q2.push({1, x, y});
        while(!Q2.empty()){
            int cnt, xx, yy;
            tie(cnt, xx, yy) = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = xx + dx[dir];
                int ny = yy + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] != '.') continue;
                if(dist[nx][ny].first == 0){
                    dist[nx][ny] = {num, dist[x][y].second + cnt};
                    if(cnt+1 > s[num]) Q1.push({num, nx, ny});
                    else Q2.push({cnt+1, nx, ny});
                }
                else if(dist[nx][ny].first == num){
                    if(dist[nx][ny].second <= dist[x][y].second + cnt) continue;
                    dist[nx][ny] = {num, dist[x][y].second + cnt};
                    if(cnt+1 > s[num]) Q1.push({num, nx, ny});
                    else Q2.push({cnt+1, nx, ny});
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans[dist[i][j].first]++;
        }
    }

    for(int i = 1; i <= p; i++)
        cout << ans[i] << " ";
}
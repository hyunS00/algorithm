#include<iostream>
#include<queue>
#include<tuple>
#define J 0
#define X 1
#define Y 2
#define endl "\n"
#define MAX 201
using namespace std;

int k, w, h;

int board[MAX][MAX];
int dist[MAX][MAX][31];

queue< tuple<int, int, int> > Q;

int jx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int jy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> k >> w >> h;

    for(int y = 0 ; y < h; y++){
        for(int x = 0; x < w; x++){
            cin >> board[y][x];
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            fill(dist[i][j], dist[i][j] + k+1, -1);
        }
    }

    dist[0][0][0] = 0;
    Q.push({0, 0, 0});

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        int j = get<J>(cur);
        int x = get<X>(cur);
        int y = get<Y>(cur);

        if(j < k) {
            for(int dir = 0; dir < 8; dir++){
                int nx = x + jx[dir];
                int ny = y + jy[dir];

                if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

                if(dist[ny][nx][j+1] >= 0 || board[ny][nx] == 1) continue;

                dist[ny][nx][j+1] = dist[y][x][j] + 1;

                Q.push({j+1,nx, ny});
            }
        }

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

            if(dist[ny][nx][j] >= 0 || board[ny][nx] == 1) continue;
            dist[ny][nx][j] = dist[y][x][j] + 1;

            Q.push({j, nx, ny});
        }
    }

    int ans = -1;
    for(int i = 0; i <= k; i++){
        if(dist[h-1][w-1][i] >= 0) {
            if(ans == -1 || dist[h-1][w-1][i] < ans) {
                ans = dist[h-1][w-1][i];
            }
        }
    }

    cout << ans << endl;
}
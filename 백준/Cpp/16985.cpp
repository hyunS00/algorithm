#include<iostream>
#include<queue>
#include<tuple>
#define X first
#define Y second

using namespace std;

const int LIMIT = 5;

int ans = LIMIT * LIMIT * LIMIT;
int board1[LIMIT][LIMIT][LIMIT];
int board2[LIMIT][LIMIT][LIMIT];
int dist[LIMIT][LIMIT][LIMIT];
int isUsed[LIMIT];
int seq[LIMIT];

queue< tuple<int, int, int> >Q;
const int dx[6] = {0, 0, 0, 1, 0, -1};
const int dy[6] = {0, 0, 1, 0, -1, 0};
const int dz[6] = {1, -1, 0, 0, 0, 0};

void solve(int k);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int f = 0; f < LIMIT; f++){
        for(int x = 0; x < LIMIT; x++){
            for(int y = 0; y < LIMIT; y++){
                cin >> board1[f][x][y];
            }
        }
    }
    solve(0);
    if(ans >= LIMIT * LIMIT * LIMIT)
        ans = -1;
    cout << ans << endl;
}

void rotate(int dir, int idx){
    int tmp[LIMIT][LIMIT];
    for(int x = 0; x < LIMIT; x++){
        for(int y = 0; y < LIMIT; y++){
            board2[idx][x][y] = board1[seq[idx]][x][y];
        }
    }

    while (dir--){
        for(int x = 0; x < LIMIT; x++){
            for(int y = 0; y < LIMIT; y++){
                tmp[x][y] = board2[idx][y][LIMIT-x-1];
            }
        }
        for(int x = 0; x < LIMIT; x++){
            for(int y = 0; y < LIMIT; y++){
                board2[idx][x][y] = tmp[x][y];
            }
        }
    }
}

void escape(){
    for(int tmp = 0; tmp < (1 << (2*LIMIT)); tmp++){
        int brute = tmp;
        for(int i = 0; i < LIMIT; i++){
            int dir = brute % 4;
            brute /= 4;
            rotate(dir, i);
        }

        if(board2[0][0][0] == 0) continue;

        for(int f = 0; f < LIMIT; f++){
            for(int x = 0; x < LIMIT; x++){
                for(int y = 0; y < LIMIT; y++){
                    dist[f][x][y] = -1;
                }
            }
        }

        Q.push({0, 0, 0});
        dist[0][0][0] = 0;

        while (!Q.empty())
        {
            int x, y, z;
            tie(x, y, z) = Q.front(); Q.pop();

            for(int dir = 0; dir < 6; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];

                if(nx < 0 || nx >= LIMIT || ny < 0 || ny >= LIMIT || nz < 0 || nz >= LIMIT)
                    continue;
                
                if(dist[nz][nx][ny] >= 0 || board2[nz][nx][ny] == 0)
                    continue;
                
                dist[nz][nx][ny] = dist[z][x][y] + 1;
                Q.push({nx, ny, nz});
            }
        }

        if(dist[LIMIT-1][LIMIT-1][LIMIT-1] > 0)
            ans = min(ans, dist[LIMIT-1][LIMIT-1][LIMIT-1]);
    }
}

void solve(int k){
    if( k >= LIMIT){
        escape();
        return;
    }

    for(int i = 0; i < LIMIT; i++){
        if(isUsed[i]) continue;
        isUsed[i]= true;
        seq[k] = i;
        solve(k+1);
        isUsed[i] = false;
    }
}
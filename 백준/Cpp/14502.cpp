#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int map[8][8];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int N, M;
int maxSaftyArea = -1;

void makeWall(int wall);
int bfs();

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    makeWall(0);

    cout << maxSaftyArea << "\n";
}

void makeWall(int wall){
    if (wall == 3){
        maxSaftyArea = max(maxSaftyArea, bfs());
        return;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (map[i][j] != 0)
                continue;
            map[i][j] = 1;
            makeWall(wall+1);
            map[i][j] = 0;
        }
    }
}

int bfs(){
    int instance_map[N][M];
    queue<pair<int,int> > q;

    for (int i = 0;i < N; i++){
        for (int j = 0; j < M; j++){
            instance_map[i][j] = map[i][j];
            if (map[i][j] == 2)
                q.push(pair<int,int>(i,j));
        }
    }

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        int lx, ly;
        q.pop();
        for (int i = 0; i < 4; i++){
            ly = pos.first + dy[i];
            lx = pos.second + dx[i];

            if (0 > ly || ly >= N || 0 > lx || lx >= M)
                continue;
            
            if (instance_map[ly][lx] == 0){
                instance_map[ly][lx] = 2;
                q.push(pair<int,int>(ly, lx));
            }
        }
    }

    int cnt = 0;
    for (int i = 0;i < N; i++){
        for (int j = 0; j < M; j++){
            if (instance_map[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}
#include<iostream>
#include<queue>
#include<vector>
#define X first
#define Y second
#define endl "\n"

using namespace std;

const int LIMIT_X = 12;
const int LIMIT_Y = 6;
int ans;
string board[LIMIT_X];

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};

queue< pair<int, int> > Q;
deque< pair<int, int> > DQ;

void drop(){
    char tmp[LIMIT_X][LIMIT_Y];

    for(int x = 0; x < LIMIT_X; x++)
        fill(tmp[x], tmp[x] + LIMIT_Y, '.');

    for(int y = 0; y < LIMIT_Y; y++){
        int idx = LIMIT_X -1;
        for(int x = LIMIT_X -1; x >= 0; x--){
            if(board[x][y] != '.'){
                DQ.push_back({idx,y});
                tmp[idx--][y] = board[x][y];
            }
        }
    }

    for(int x = 0; x < LIMIT_X; x++){
        for(int y = 0; y < LIMIT_Y; y++){
            board[x][y] = tmp[x][y];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(int x = 0; x < LIMIT_X; x++){
        cin >> board[x];
        for(int y = 0; y < LIMIT_Y; y++){
            if(board[x][y] != '.')
                DQ.push_back({x, y});
        }
    }

    do {
        bool isBurst = false;
        while (!DQ.empty()){
            int x = DQ.front().X;
            int y = DQ.front().Y;
            DQ.pop_front();
            if(board[x][y] == '.') continue;
            vector< pair<int, int> > puyo;
            bool visited[LIMIT_X][LIMIT_Y] = {};
            visited[x][y] = true;

            char c = board[x][y];
            Q.push({x, y});
            puyo.push_back({x, y});
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= LIMIT_X || ny < 0 || ny >= LIMIT_Y) continue;
                    if(visited[nx][ny] || board[nx][ny] != c) continue;
                    visited[nx][ny] = true;
                    Q.push({nx, ny});
                    puyo.push_back({nx, ny});
                }
            }

            if(puyo.size() >= 4){
                while (!puyo.empty()) {
                    auto cur = puyo.back(); puyo.pop_back();
                    board[cur.X][cur.Y] = '.';
                }
                isBurst = true;
            }
        }
        if(isBurst){
            drop();
            ans++;
        }
    } while(!DQ.empty());

    cout << ans << endl;
}
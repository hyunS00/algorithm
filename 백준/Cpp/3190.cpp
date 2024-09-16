#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

const int LIMIT = 100;

int n, k, l;
int board[LIMIT][LIMIT];
deque< pair<int, int> > snake;
pair<int, char> com[LIMIT];

int t, dir;
char c;
int ci;
// 동 남 서 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 1;
    }
    
    cin >> l;

    for(int i = 0; i < l; i++){
        int tt;
        char cc;
        cin >> tt >> cc;
        com[i] = {tt, cc};
    }

    snake.push_front({0, 0});
    board[0][0] = 2;

    while (true)
    {
        t++;
        int x, y;
        tie(x, y) = snake.front();
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;
        if(board[nx][ny] == 2) break;
        if(board[nx][ny] != 1){
            int px, py;
            tie(px, py) = snake.back(); snake.pop_back();
            board[px][py] = 0;
        }
        board[nx][ny] = 2;
        snake.push_front({nx, ny});

        if(ci < l && com[ci].first == t){
            if(com[ci].second == 'L'){
                dir =  (dir + 3) % 4;
            }
            else {
                dir = (dir+1) % 4;
            }
            ci++;
        }
    }
    cout << t << endl;
}
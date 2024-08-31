#include<iostream>
#include<queue>
#include<algorithm>
#define end "\n"
#define X first
#define Y second

using namespace std;

const int MAX = 25;

int n;

string board[MAX];
int dist[MAX][MAX];
int house[MAX*MAX];
queue< pair<int, int> > Q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> board[i];

    int cnt = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(dist[x][y] > 0 || board[x][y] == '0') continue;

            dist[x][y] = ++cnt;
            Q.push({x, y});
            while (!Q.empty())
            {
                auto cur = Q.front(); Q.pop();
                house[cnt]++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(dist[nx][ny] > 0 || board[nx][ny] == '0') continue;

                    dist[nx][ny] = dist[cur.X][cur.Y];
                    Q.push({nx, ny});
                }
            }      
        }
    }
    cout << cnt << endl;
    sort(house, house+cnt+1);
    for(int i = 1; i <= cnt; i++){
        cout << house[i] << endl;
    }
}
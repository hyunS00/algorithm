#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define X first
#define Y second
#define endl "\n"

using namespace std;

const int MAX = 100;

int n, m, k;
int board[MAX][MAX];
int visited[MAX][MAX];
vector<int> ans;
queue< pair <int, int> > Q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> k;

    int num = 0;
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        board[y1][x1] = ++num;
        Q.push({x1, y1});

        while (!Q.empty())
        {
            auto cur = Q.front(); Q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < x1 || nx >= x2 || ny < y1 || ny >= y2) continue;

                if(board[ny][nx] == board[cur.Y][cur.X]) continue;
                board[ny][nx] = board[cur.Y][cur.X];
                Q.push({nx, ny});
            }
        }
    }

    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            if(visited[y][x] || board[y][x] > 0) continue;
            visited[y][x] = true;
            Q.push({x, y});
            int cnt = 1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    if(board[ny][nx] > 0 || visited[ny][nx]) continue;
                    visited[ny][nx] = true;
                    cnt++;
                    Q.push({nx, ny});
                }
            }
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}
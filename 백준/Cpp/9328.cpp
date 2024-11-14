#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#define X first
#define Y second
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    while(t--){
        int h, w;
        cin >> h >> w;
        vector<string> board(h);
        for(int x = 0; x < h; x++) cin >> board[x];
        
        int key[27];
        fill(key, key + 27, 0);
        vector<vector<pair<int, int>>> door(27, vector<pair<int, int>>());

        string keys;
        cin >> keys;
        if(keys != "0"){
            for(char c : keys){
                key[c - 'a' + 1] = 1;
            }
        }

        queue<pair<int, int>> Q;
        bool visited[100][100];
        for(int x = 0; x < h; x++) fill(visited[x], visited[x] + w, false);
        int ans = 0;

        for(int x = 0; x < h; x++){
            for(int y = 0; y < w; y++){
                if(x != 0 && x != h-1 && y != 0 && y != w-1) continue;
                char current = board[x][y];
                if(current == '*') continue;
                if(current == '$') ans++;
                if(current >= 'a' && current <= 'z'){
                    if(!key[current - 'a' + 1]){
                        key[current - 'a' + 1] = 1;
                        while(!door[current - 'a' + 1].empty()){
                            auto nxt = door[current - 'a' + 1].back();
                            door[current - 'a' + 1].pop_back();
                            if(!visited[nxt.X][nxt.Y]){
                                Q.push(nxt);
                                visited[nxt.X][nxt.Y] = true;
                            }
                        }
                    }
                }
                if(current >= 'A' && current <= 'Z'){
                    if(!key[current - 'A' + 1]){
                        door[current - 'A' + 1].push_back({x, y});
                        continue;
                    }
                }
                if(!visited[x][y]){
                    Q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }

        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(visited[nx][ny] || board[nx][ny] == '*') continue;

                char current = board[nx][ny];
                if(current == '$'){
                    ans++;
                }
                if(current >= 'a' && current <= 'z'){
                    if(!key[current - 'a' + 1]){
                        key[current - 'a' + 1] = 1;
                        while(!door[current - 'a' + 1].empty()){
                            auto nxt = door[current - 'a' + 1].back();
                            door[current - 'a' + 1].pop_back();
                            if(!visited[nxt.X][nxt.Y]){
                                Q.push(nxt);
                                visited[nxt.X][nxt.Y] = true;
                            }
                        }
                    }
                }
                if(current >= 'A' && current <= 'Z'){
                    if(!key[current - 'A' + 1]){
                        door[current - 'A' + 1].push_back({nx, ny});
                        continue;
                    }
                }
                Q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        cout << ans << endl;
    }
}

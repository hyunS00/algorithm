#include<iostream>
#include<queue>

using namespace std;

char board[5][5];
bool visited[5][5];
bool isPrince[5][5];
int student[7];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans;

void func(int idx, int som, int yeon, int cnt);
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            cin >> board[x][y];
        }
    }

    func(-1, 0, 0, 0);
    cout << ans << endl;
}

void func(int idx, int som, int yeon, int cnt){
    if(yeon > 3)
        return;
    if(cnt >= 7){
        int x = idx / 5;
        int y = idx % 5;
        queue< pair<int, int> >Q;
        bool check[5][5] = {};
        Q.push({x, y});
        int cnt = 1;
        check[x][y] = true;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if(check[nx][ny] || !isPrince[nx][ny]) continue;
                check[nx][ny] = true;
                Q.push({nx, ny});
                cnt++;
            }
        }

        if(cnt >= 7)
            ans++;
        return;
    }

    for(int i = idx + 1; i < 25; i++){
        int x = i / 5;
        int y = i % 5;

        if(visited[x][y]) continue;

        visited[x][y] = true;
        isPrince[x][y] = true;

        if(board[x][y] == 'Y')
            func(i, som, yeon + 1, cnt + 1);
        else
            func(i, som + 1, yeon, cnt + 1);

        visited[x][y] = false;
        isPrince[x][y] = false;
    }
}
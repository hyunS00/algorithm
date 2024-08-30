#include<iostream>
#include<vector>
#define endl "\n"
#define MAX 20

using namespace std;

int n;
int board[MAX][MAX];
pair<int, int> student[MAX*MAX] = {{-1, -1}};
vector< vector<int> > liked;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int findLikedStudent(int student, int x, int y);

int findEmtySpace(int x, int y);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    liked.resize(n*n+1);

    for(int i = 0 ; i < n*n; i++){
        int s;
        cin >> s;
        for(int j = 0; j < 4; j++){
            int num;
            cin >> num;
            liked[s].push_back(num);
        }
        int maxLikeCnt = -1;
        int maxEmtyCnt = -1;
        int nx = -1;
        int ny = -1;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(board[x][y] > 0) continue;

                int likeCnt = findLikedStudent(s, x, y);
                int emtyCnt = findEmtySpace(x, y);
                if(maxLikeCnt < likeCnt){
                    maxLikeCnt = likeCnt;
                    maxEmtyCnt = emtyCnt;
                    nx = x;
                    ny = y;
                }
                else if(maxLikeCnt == likeCnt && maxEmtyCnt < emtyCnt){
                    maxEmtyCnt = emtyCnt;
                    nx = x;
                    ny = y;
                }
            }
        }
        board[nx][ny] = s;
    }
    int ans = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            int cnt = findLikedStudent(board[x][y],x, y);

            if(cnt ==1) ans += 1;
            else if(cnt == 2) ans += 10;
            else if(cnt == 3) ans += 100;
            else if(cnt == 4) ans += 1000;
        }
    }
    cout << ans << endl;;
}

int findLikedStudent(int student, int x, int y){
    int cnt = 0;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        for(int i = 0; i < 4; i++){
            int s = liked[student][i];
            if(board[nx][ny] == s)
                cnt++;
        }
    }
    return cnt;
}

int findEmtySpace(int x, int y){
    int cnt = 0;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

        if(board[nx][ny] == 0)
            cnt++;
    }
    return cnt;
}
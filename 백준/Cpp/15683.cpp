#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

const int LIMIT = 8;
const int dx[4] = {0, 1, 0, -1};  // 오른쪽, 아래, 왼쪽, 위
const int dy[4] = {1, 0, -1, 0};

int n, m, ans;
vector<vector<int>> board(LIMIT, vector<int>(LIMIT, 0));
vector<pair<int, int>> cctv;

void watch(int x, int y, int dir, vector<vector<int>>& watched) {
    int nx = x + dx[dir], ny = y + dy[dir];
    while (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 6) {
        watched[nx][ny] = 1;
        nx += dx[dir];
        ny += dy[dir];
    }
}

int count_blind_spots(const vector<vector<int>>& watched) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && !watched[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void solve(int index, vector<vector<int>>& watched) {
    if (index == cctv.size()) {
        ans = min(ans, count_blind_spots(watched));
        return;
    }

    int x = cctv[index].first, y = cctv[index].second;
    int type = board[x][y];

    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> new_watched = watched;
        
        if (type == 1) {
            watch(x, y, dir, new_watched);
        } else if (type == 2) {
            watch(x, y, dir, new_watched);
            watch(x, y, (dir + 2) % 4, new_watched);
        } else if (type == 3) {
            watch(x, y, dir, new_watched);
            watch(x, y, (dir + 1) % 4, new_watched);
        } else if (type == 4) {
            watch(x, y, dir, new_watched);
            watch(x, y, (dir + 1) % 4, new_watched);
            watch(x, y, (dir + 2) % 4, new_watched);
        } else if (type == 5) {
            for (int i = 0; i < 4; i++) {
                watch(x, y, i, new_watched);
            }
        }

        solve(index + 1, new_watched);

        if (type == 5) break;  // 5번 CCTV는 한 번만 처리
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6) {
                cctv.push_back({i, j});
            }
        }
    }

    vector<vector<int>> initial_watched(n, vector<int>(m, 0));
    ans = n * m;  // 최대 가능한 사각지대 크기로 초기화
    solve(0, initial_watched);

    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[500][500];

vector<vector<pair<int, int>>> tetrominos = {
    {{0,0}, {0,1}, {0,2}, {0,3}}, {{0,0}, {1,0}, {2,0}, {3,0}},
    {{0,0}, {0,1}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {2,0}, {2,1}}, {{0,0}, {1,0}, {2,0}, {0,1}},
    {{0,0}, {0,1}, {0,2}, {1,0}}, {{0,0}, {0,1}, {0,2}, {1,2}},
    {{0,0}, {1,0}, {1,1}, {1,2}}, {{0,2}, {1,0}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {0,2}, {1,1}}, {{0,1}, {1,0}, {1,1}, {2,1}},
    {{0,0}, {0,1}, {1,1}, {1,2}}, {{0,1}, {1,0}, {1,1}, {2,0}},
    {{0,0}, {1,0}, {1,1}, {2,0}}, {{0,1}, {1,0}, {1,1}, {2,1}},
    {{0,1}, {1,0}, {1,1}, {1,2}}, {{0,0}, {0,1}, {0,2}, {1,1}},
    {{0,0}, {1,0}, {1,1}, {2,1}}, {{0,1}, {0,2}, {1,0}, {1,1}},
    {{0,0}, {0,1}, {1,1}, {2,1}}, {{0,1}, {1,1}, {2,0}, {2,1}},
    {{0,0}, {1,0}, {2,0}, {2,-1}}, {{0,0}, {0,1}, {1,0}, {2,0}},
    {{0,0}, {0,1}, {0,2}, {-1,2}}, {{0,0}, {1,0}, {0,1}, {0,2}},
    {{0,0}, {0,1}, {1,0}, {2,0}}, {{0,0}, {0,1}, {0,2}, {1,0}}
};

int calculate(int x, int y, const vector<pair<int, int>>& tetromino) {
    int sum = 0;
    for (auto [dx, dy] : tetromino) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) return 0;
        sum += board[nx][ny];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (const auto& tetromino : tetrominos) {
                answer = max(answer, calculate(i, j, tetromino));
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
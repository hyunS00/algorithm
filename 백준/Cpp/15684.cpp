#include <iostream>
#include <algorithm>

using namespace std;

int n, m, h, mn = 4;
bool ladder[31][11];

bool check() {
    for (int i = 1; i <= n; i++) {
        int pos = i;
        for (int j = 1; j <= h; j++) {
            if (ladder[j][pos]) pos++;
            else if (ladder[j][pos-1]) pos--;
        }
        if (pos != i) return false;
    }
    return true;
}

void solve(int x, int y, int cnt) {
    if (cnt >= mn) return;
    if (check()) {
        mn = min(mn, cnt);
        return;
    }
    if (cnt == 3) return;

    for (int i = y; i <= h; i++) {
        for (int j = x; j < n; j++) {
            if (ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
            ladder[i][j] = true;
            solve(j+1, i, cnt + 1);
            ladder[i][j] = false;
        }
        x = 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    solve(1, 1, 0);

    cout << (mn > 3 ? -1 : mn) << endl;
    return 0;
}
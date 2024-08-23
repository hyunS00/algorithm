#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;

int bfs(int n, int k) {
    vector<int> dist(MAX, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == k) return dist[cur];

        for (int nx : {cur * 2, cur + 1, cur - 1}) {
            if (nx < 0 || nx >= MAX-1) continue;

            if(dist[nx] != -1) continue;
            
            dist[nx] = (nx == cur * 2) ? dist[cur] : dist[cur] + 1;
            q.push(nx);
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << bfs(n, k) << '\n';

    return 0;
}
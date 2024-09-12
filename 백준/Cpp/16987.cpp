#include<iostream>
#define endl "\n"

using namespace std;

const int MAX = 8;

int n;
pair<int, int> egg[MAX];
int mx = 0;

void func(int idx, int cnt) {
    if (idx == n || cnt == n) {  // 모든 계란을 확인했거나 모든 계란이 깨진 경우
        mx = max(mx, cnt);
        return;
    }

    if (egg[idx].first <= 0) {
        func(idx + 1, cnt);
        return;
    }

    bool allBroken = true;
    for (int i = 0; i < n; i++) {
        if (i != idx && egg[i].first > 0) {
            allBroken = false;
            egg[i].first -= egg[idx].second;
            egg[idx].first -= egg[i].second;

            int broken = cnt;
            if (egg[i].first <= 0) broken++;
            if (egg[idx].first <= 0) broken++;

            func(idx + 1, broken);

            egg[i].first += egg[idx].second;
            egg[idx].first += egg[i].second;
        }
    }

    if (allBroken) {
        mx = max(mx, cnt);  // 모든 다른 계란이 깨졌다면 현재 상태가 최대값
        return;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, w;
        cin >> s >> w;
        egg[i] = {s, w};
    }

    func(0, 0);

    cout << mx << endl;
}
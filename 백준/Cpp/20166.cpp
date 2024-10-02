#include<iostream>
#include<unordered_map>
#define endl "\n"
using namespace std;

int n, m, k;
char board[11][11];

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
unordered_map<string, int> s2i;

void func(int d, string s,int x, int y){
    if(d >= 5){
        return;
    }

    s += board[x][y];
    s2i[s]++;

    for(int dir = 0; dir < 8; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0) nx = n-1;
        if(nx >= n) nx = 0;
        if(ny < 0) ny = m-1;
        if(ny >= m) ny = 0;

        func(d+1, s, nx, ny);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            cin >> board[x][y];

    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            func(0, "", x, y);

    while (k--) {
        string word;
        cin >> word;
        cout << s2i[word] << endl;
    }
}
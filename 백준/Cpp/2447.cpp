#include<iostream>
#define endl "\n";

using namespace std;

int c;
char star[6561][6561];

void solve(int x, int y, int c);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> c;
    for (int i = 0; i < c; i++)
        fill(star[i], star[i]+c, ' ');

    solve(0, 0, c);

    for(int i = 0; i < c; i++){
        cout << star[i] << endl;
    }
}

void solve(int x, int y, int c){
    if(c == 1) {
        star[x][y] = '*';
        return;
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1) continue;
            solve(x + c / 3 * i, y + c / 3 * j, c / 3);
        }
    }
}
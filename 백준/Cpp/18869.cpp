#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;
const int LIMIT = 10000;

int m, n;
int universe[100][LIMIT];
vector<int> com[100];
int cnt;
int arr[2];
void solve(int k, int s){
    if(k >= 2){
        for(int i = 0; i < m; i++){
            int n1 = arr[0];
            int n2 = arr[1];
            int a = universe[n1][i];
            int b = universe[n2][i];
            if(lower_bound(com[n1].begin(), com[n1].end(), a) - com[n1].begin() != lower_bound(com[n2].begin(), com[n2].end(), b) - com[n2].begin())
                return;
        }
        cnt++;
        return;
    }

    for(int i = s; i < m; i++){
        arr[k] = i;
        solve(k+1, i+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> universe[i][j];
            com[i].push_back(universe[i][j]);
        }
        sort(com[i].begin(), com[i].end());
        com[i].erase(unique(com[i].begin(), com[i].end()), com[i].end());
    }
    
    solve(0, 0);
    cout << cnt << endl;
}
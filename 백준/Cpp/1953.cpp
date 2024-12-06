#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> adj[101];
int color[101];
vector<int> team[3];
void func(int v, int c){
    color[v] = c;
    team[c].push_back(v);
    for(int nxt : adj[v]){
        if(color[nxt]) continue;
        func(nxt, 3-c);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int size;
        cin >> size;
        adj[i].resize(size);
        for(int j = 0; j < size; j++)
            cin >> adj[i][j];
    }

    for(int i = 1; i <= n; i++){
        if(color[i]) continue;
        func(i, 1);
    }

    sort(team[1].begin(), team[1].end());
    sort(team[2].begin(), team[2].end());

    cout << team[1].size() << endl;
    for(int i : team[1])
        cout << i << " ";
    cout << endl;
    cout << team[2].size() << endl;
    for(int i : team[2])
        cout << i << " ";

}
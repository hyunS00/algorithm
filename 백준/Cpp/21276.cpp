#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int n, m;
unordered_map<string, int> s2i;
string i2s[1005];
vector<int> children[1005];
vector<int> adj[1005];
int deg[1005];
queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> i2s[i];
    
    sort(i2s+1, i2s+n+1);

    for(int i = 1; i <= n; i++)
        s2i[i2s[i]] = i;

    cin >> m;
    for(int i = 0; i < m; i++){
        string x, y;
        cin >> x >> y;
        deg[s2i[x]]++;
        adj[s2i[y]].push_back(s2i[x]);
    }

    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> grand;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0){
            Q.push(i);
            grand.push_back(i);
        } 
    }

    cout << grand.size() << endl;
    for(int i : grand)
        cout << i2s[i] << " ";
    cout << endl;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0){
                Q.push(nxt);
                children[cur].push_back(nxt);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << i2s[i] << " " << children[i].size() << " ";
        for(int j : children[i])
            cout << i2s[j] << " ";
        cout << endl;
    }
}
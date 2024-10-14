#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;

int n, m;
unordered_multiset<string> s1;
unordered_multiset<string> s2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        s1.insert(name);
    }

    for(int i = 0; i < m; i++){
        string name;
        cin >> name;
        s2.insert(name);
    }

    vector<string> ans;
    for(string name : s1){
        if(s2.find(name) != s2.end()) ans.push_back(name);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(string name : ans)
        cout << name << endl;
}
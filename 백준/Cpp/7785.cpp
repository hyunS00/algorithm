#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int n;
unordered_map<string, string> m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        string state;
        cin >> name >> state;
        m[name] = state;
    }

    vector<string> ans;
    for(auto kv: m)
        if(kv.second == "enter") ans.push_back(kv.first);

    sort(ans.begin(), ans.end(), greater<string>());

    for(auto s: ans)
        cout << s << endl;
}
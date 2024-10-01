#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;

int k, l;
unordered_map<string, int> s2i;
bool cmp(pair<string, int> &a, pair<string, int> &b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> l;

    for(int i = 0; i < l; i++){
        string name;
        cin >> name;
        s2i[name] = i;
    }

    vector< pair<string, int> > v(s2i.begin(), s2i.end());
    sort(v.begin(), v.end(), cmp);

    int mn = min(k, (int)v.size());
    for(int i = 0; i < mn; i++)
        cout << v[i].first << endl;
}
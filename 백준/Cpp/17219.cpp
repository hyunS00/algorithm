#include<iostream>
#include<unordered_map>
#define endl "\n"
using namespace std;

int n, m;
unordered_map<string, string> s2s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string url, pw;
        cin >> url >> pw;
        s2s[url] = pw;
    }

    for(int i = 0; i < m; i++){
        string url;
        cin >> url;
        cout << s2s[url] << endl;
    }
}
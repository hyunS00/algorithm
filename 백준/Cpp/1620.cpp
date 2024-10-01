#include<iostream>
#include<unordered_map>
#define endl "\n"
using namespace std;

int n, m;
unordered_map<string, int> s2i;
string i2s[100005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> i2s[i];
        s2i[i2s[i]] = i;
    }

    while (m--) {
        string query;
        cin >> query;
        if(isdigit(query[0]))
            cout << i2s[stoi(query)] << endl;
        else
            cout << s2i[query] << endl;
    }
    
}
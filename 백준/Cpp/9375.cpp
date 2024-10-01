#include<iostream>
#include<unordered_map>
#define endl "\n"
using namespace std;

int t;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<string, int> s2i;

        for(int i = 0; i < n; i++){
            string name, kind;
            cin >> name >> kind;
            s2i[kind]++;
        }

        int ans = 1;
        for(auto tmp : s2i)
            ans *= tmp.second + 1;

        cout << ans-1 << endl;
    }
}
#include<iostream>
#include<set>
#define endl "\n"
using namespace std;

int t;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        int k;
        multiset<int> ms;
        cin >> k;
        while (k--) {
            char c;
            int n;
            cin >> c >> n;
            if(c == 'I') ms.insert(n);
            else if(ms.empty()) continue;
            else if(n == 1) ms.erase(prev(ms.end()));
            else if(n == -1) ms.erase(ms.begin());
        }
        if(ms.empty()) cout << "EMPTY" << endl;
        else cout << *prev(ms.end()) <<  " " << *ms.begin() <<  endl;;
    }
}
#include<iostream>
#include<set>
#define endl "\n"
using namespace std;

int n, m;
set<pair<int, int>> s;
int problem[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int p, l;
        cin >> p >> l;
        s.insert({l, p});
        problem[p] = l;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        string com;
        cin >> com;
        if(com == "add"){
            int p, l;
            cin >> p >> l;
            s.insert({l, p});
            problem[p] = l;
        }
        else if(com == "recommend"){
            int x;
            cin >> x;
            if(x == 1) cout << (*prev(s.end())).second << endl;
            else if(x == -1) cout << (*s.begin()).second << endl;
        }
        else if(com == "solved"){
            int p, l;
            cin >> p;
            l = problem[p];
            s.erase({l, p});
        }
    }
}
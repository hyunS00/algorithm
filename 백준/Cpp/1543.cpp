#include<iostream>
using namespace std;

string a,b;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    getline(cin, a);
    getline(cin, b);

    int cnt = 0;
    int nxtp = a.find(b);
    while (nxtp != string::npos) {
        nxtp = a.find(b, nxtp + b.size());
        cnt++;
    }
    
    cout << cnt;
}
#include<iostream>
using namespace std;

string s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-i-1]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S="";
    char input;
    

    for(int i=0 ;i<8 ;i++){
        cin >> input;
        S += input;
    }

    string ans = "mixed";
    if(S == "12345678"){
        ans = "ascending";
    }else if(S == "87654321"){
        ans = "descending";
    }
    cout << ans << endl;
}
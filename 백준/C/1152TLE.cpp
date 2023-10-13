#include <bits/stdc++.h>
using namespace std;

size_t countWord(string &str, char deliiter){
    vector<string>ret;
    ret.clear();
    size_t pos = str.find(deliiter);
    size_t initialPos = 0;
    string token;
    while(pos != string::npos){
        token = str.substr(initialPos,pos-initialPos);
        if(token != "\0"){
            ret.push_back(token);
        }
        initialPos = pos + 1;
        pos = str.find(deliiter, initialPos);
    }
    token = str.substr(initialPos,min(pos,str.size()) - initialPos +1);
    if(token != "\0"){
        ret.push_back(token);
    }
    return ret.size();
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    string S;
    getline(cin,S);

    int ans=0;
    ans = countWord(S,' ');

    cout << ans << endl;
}
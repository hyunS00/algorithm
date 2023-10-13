#include<bits/stdc++.h>
using namespace std;

vector<string> split(string &str, string delimiter){
    vector<string> ret;
    ret.clear();
    size_t pos = 0;
    size_t initialPos = 0;
    pos = str.find(delimiter);
    while(pos != string::npos){
        ret.push_back(str.substr(initialPos,pos-initialPos));
        initialPos = pos + 1;
        pos = str.find(delimiter,initialPos);
    }
    ret.push_back(str.substr(initialPos,min(pos,str.size())-initialPos+1));
    return ret;
}

int main(){
    string S;
    getline(cin,S);

    vector<string> splitStr;
    splitStr = split(S," ");
    long long checkNum = 0;

    cout << endl;
    for(string str : splitStr){
        checkNum += pow((int)str[0]-48,2);
    }
    checkNum %= 10;
    cout << checkNum << endl;
}
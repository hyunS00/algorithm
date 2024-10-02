#include<iostream>
using namespace std;

string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string word;
    cin >> word;

    for(auto s: alpha){
        int pos = word.find(s);
        while (pos != string::npos) {
            word.replace(pos, s.size(), "1");
            pos = word.find(s, pos);
        }
    }

    cout << word.size();
}
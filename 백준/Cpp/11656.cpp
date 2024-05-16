#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string word;
vector<string> S;

bool cmp(string s1, string s2);

int main(){
    cin >> word;

    for(int i = 0; i < word.length(); i++){
        S.push_back(word.substr(i, word.length() - i));
    }
    sort(S.begin(), S.end(), cmp);

    for (string s : S){
        cout << s <<"\n";
    }
}

bool cmp(string s1, string s2){
    int n1, n2;
    n1 = 0;
    n2 = 0;
    while (s1[n1] == s2[n2] && n1 < s1.length() && n2 < s2.length())
    {
        n1++;
        n2++;
    }
    return s1[n1] < s2[n2];
}
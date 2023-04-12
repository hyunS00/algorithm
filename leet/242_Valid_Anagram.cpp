#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
    vector<int>s_alpabet(26);
    vector<int>t_alpabet(26);
    for(char str:s)
        s_alpabet[str-'a']++;

    for(char str:t)
        t_alpabet[str-'a']++;
    
    for(int i=0;i<26;i++){
        if(s_alpabet[i]!=t_alpabet[i])
            return false;
    }
    return true;
}

int main(){
    string s= "rat";
    string t = "car";
    bool result = isAnagram(s,t);

    cout<< result<<"\n";
}
#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {
    vector<int>alpabet(26);
    for(char str:s)
        alpabet[str-'a']++;

    for(int i=0;i<s.size();i++){
        if(alpabet[s[i]-'a']==1)
            return i;
    }
    return -1;
}
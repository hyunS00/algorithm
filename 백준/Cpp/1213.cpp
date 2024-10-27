#include<iostream>
using namespace std;

string s;
char pal[51];
int alpha[26];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        alpha[s[i]-'A']++;
    int idx = 0;
    for(int i = 0; i < 26; i++){
        if(alpha[i] == 0) continue;
        if(alpha[i] % 2 == 1){
            if(pal[s.size()/2]){
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            pal[s.size()/2] = i+'A';
            alpha[i]--;
        }

        while(alpha[i]){
            pal[idx] = i+'A';
            pal[s.size() - idx-1] = i+'A';
            alpha[i] -= 2;
            idx++;
        }
    }

    for(int i = 0; i < s.size(); i++)
        cout << pal[i];
}
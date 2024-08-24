#include<iostream>
#define endl "\n"

using namespace std;

string word;
int cur, ans;

bool isPal(int idx);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> word;
    ans = word.size();

    for(int i = 0; i < word.size(); i++){
        if(isPal(i)){
            cout << ans << endl;
            return 0;
        }
        ans++;
    }
}

bool isPal(int idx){
    for(int i = idx; i < word.size()/2; i++){
        if(word[i] != word[word.size()-i -1]){
            word += word[idx];
            return false;   
        }
    }
    return true;
}
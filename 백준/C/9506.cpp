#include<bits/stdc++.h>
using namespace std;

bool compareSize(string s1, string s2){
    return s1.size() < s2.size();
}

int main(){
    int N;
    cin >> N;
    vector<string> words;
    string word;
    for(int i=0; i<N;i++){
        cin >> word;
        words.push_back(word);
    }
    sort(words.begin(),words.end(),compareSize);

    int initialPos = 0;
    for(int pos=0; pos<N;pos++){
        if(words[initialPos].size()!=words[pos].size()){
            sort(words.begin()+initialPos,words.begin()+pos);
            initialPos = pos;
        }
    }
    sort(words.begin()+initialPos,words.end());
    words.erase(unique(words.begin(),words.end()),words.end());

    for(auto str : words) {
        cout << str <<endl;
    }
}
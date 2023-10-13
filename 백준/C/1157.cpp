#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    vector<int> alpabet(26);

    for(int askiCode : S){
        if(askiCode <97){
            ++alpabet[askiCode-65];
        }else{
            ++alpabet[askiCode-97];
        }
    }
    
    int maxIndex = 0;
    vector <int> maxIndexes;
    maxIndexes.push_back(maxIndex);
    for(int i=1; i< alpabet.size();i++){
        if(alpabet[i]> alpabet[maxIndex]){
            maxIndex = i;
            maxIndexes.clear();
            maxIndexes.push_back(maxIndex);
        } else if(alpabet[i] ==  alpabet[maxIndex]){
            maxIndexes.push_back(maxIndex);
        }
    }

    if(maxIndexes.size()>=2){
        cout << "?" << endl;
    }else{
        cout << (char)(maxIndex+65) << endl;
    }
}
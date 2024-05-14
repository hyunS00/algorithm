#include<iostream>
#include<vector>
using namespace std;

string sentence;
vector<int> alpha(26);

int main(){
    cin >> sentence;

    for(int i : sentence){
        alpha[i - 97]++;
    }

    for(int i : alpha){
        cout << i << " ";
    }
    cout <<"\n";
}
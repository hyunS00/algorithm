#include<iostream>
using namespace std;

int N, five;

int main(){
    cin >> N;
    for(int i = 1; i<= N; i++){
        if(i % 5 == 0)
            five++;
        if(i % 25 == 0)
            five++;
        if(i % 125 == 0)
            five++;
    }

    cout << five << "\n";
}
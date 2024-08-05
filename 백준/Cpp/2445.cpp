#include<iostream>
#define endl "\n"

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < i; j++)cout << "*";
        for(int j = 0; j < n*2 - (i*2); j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "*";
        cout << endl;
    }

    for(int i = 0; i < n*2; i++) cout << "*";
    cout << endl;

    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j < i; j++) cout << "*";
        for(int j = 0; j < n*2 - (i*2); j++) cout << " ";
        for(int j = 0; j < i; j++)cout << "*";
        cout << endl;
    }
}
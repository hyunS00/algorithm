#include<iostream>
#define endl "\n"

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = n; i >=0; i--){
        for(int j = 0; j < i ; j++){
            cout << "*";
        }
        cout << endl;
    }
}
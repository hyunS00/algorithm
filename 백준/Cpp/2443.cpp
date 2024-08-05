#include <iostream>
#define endl "\n"

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i-1; j++){
            cout << " ";
        }

        for(int j = 0; j < n*2 - (i*2-1); j++){
            cout << "*";
        }
        cout << endl;
    }
}
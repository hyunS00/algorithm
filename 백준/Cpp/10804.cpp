#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int num[21];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    for(int i = 1; i <= 20; i++){
        num[i] = i;
    }

    for(int i = 0 ; i < 10;i++){
        int a,b;
        cin >> a >> b;

        int differ = b - a;
        for(int i = 0; i <= differ/2; i++){
            swap(num[a+i],num[b-i]);
        }
    }

    for(int i = 1; i <= 20; i++){
        cout << num[i] << " ";
    }

    cout << endl;
}
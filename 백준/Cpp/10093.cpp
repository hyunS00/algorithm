#include<iostream>
#define endl "\n"

using namespace std;

long long A,B;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> A >> B;

    if(A > B) swap(A, B);
    if(A == B || B - A == 1)
        cout << 0 << endl;
    else
        cout << B - A -1 << endl;

    for(long long i = A+1; i < B; i++){
        cout << i << " ";
    }
    cout  << endl;
}
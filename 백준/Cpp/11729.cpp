#include<iostream>
#define endl "\n"

using namespace std;

void hanoi(int a, int b, int n);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    hanoi(1, 3, n);
}

void hanoi(int a, int b, int n){
    if(n == 0) return;

    hanoi(a, 6-a-b, n-1);
    cout << a << " " << b << endl;
    hanoi(6-a-b, b, n-1);
}
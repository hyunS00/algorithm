#include<iostream>
#define endl "\n"
using namespace std;

int t;
int m, n, x, y;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}
int chk(){
    if(x == m) x = 0;
    if(y == n) y = 0;
    int l = lcm(m, n);
    for(int i = x; i <= l; i += m){
        if(i == 0) continue;
        if(i % n == y)
            return i;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        cout << chk() << endl;
    }
}
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[100], b[100];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);

    int s = 0;
    for(int i = 0; i < n; i++)
        s += a[i] * b[n-i-1];
    
    cout << s << endl;
}
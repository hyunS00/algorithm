#include<iostream>
#include<algorithm>

using namespace std;

int n;
int rope[100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> rope[i];
    
    sort(rope, rope+n);

    int mx = 0;
    for(int i = 0; i < n; i++)
        mx = max(mx, rope[i]*(n-i));
    
    cout << mx << endl;
}
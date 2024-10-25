#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
int a[55];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n < 3){
        cout << n;
        return 0;
    }
    
    sort(a, a+n);

    int mx = 2;
    int st = 0;
    for(int en = 2; en < n; en++){
        while(st+1 < en && a[st] + a[st+1] <= a[en]) st++;

        if(a[st]+a[st+1] > a[en])
            mx = max(mx, en-st+1);
    }

    cout << mx;
}
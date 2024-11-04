#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[3000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);
    int mx = 0;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(mx < (a[i+1]-a[i])/2){
            mx = (a[i+1]-a[i])/2;
            ans = a[i]+mx;
        }
    }

    if(mx <= 0) ans = -1;
    cout << ans;
}
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
int a[10005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    ll cnt = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int sum = a[i] + a[j];
            int lb = lower_bound(a+j+1, a+n, -sum) - a;
            int ub = upper_bound(a+j+1, a+n, -sum)  - a;
            cnt += ub - lb;
        }
    }

    cout << cnt;
}
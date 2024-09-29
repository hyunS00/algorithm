#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int n, cnt;
ll a[2001];

void solve(int k){
    for(int i = 0; i < n; i++){
        if(i == k) continue;
        int x = a[k] - a[i];
        int idx = lower_bound(a, a + n, x) - a;
        while (idx < n && a[idx] == x) {
            if(idx != i && idx != k) {cnt++; return;}
            idx++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    for(int k = 0; k < n; k++) solve(k);

    cout << cnt;
}
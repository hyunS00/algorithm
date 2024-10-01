#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int m, n;
int a[1000005];

bool solve(int mid) {
    ll cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += a[i] / mid;
    
    return cnt >= m;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    int st = 0;
    int en = a[n-1];
    while (st < en) {
        int mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    
    cout << st;
}
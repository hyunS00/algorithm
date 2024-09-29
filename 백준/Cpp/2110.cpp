#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, c;
ll a[200001];

bool solve(int len){
    int idx = 0, cnt = 0;
    while (idx != n) {
        idx = lower_bound(a + idx, a + n, a[idx] + len) - a;
        cnt++;
    }
    return cnt >= c;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    int st = 0;
    int en = a[n-1];
    while (st < en)
    {
        int mid = (st + en+1) / 2;
        if(solve(mid)) st = mid;
        else en = mid -1;
    }
    
    cout << st;
}
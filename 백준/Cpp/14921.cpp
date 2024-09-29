#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll a[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans1 = 1e9+1;
    ll ans2 = 1e9+1;

    for(int i = 0; i < n-1; i++){
        int st = i+1;
        int en = n-1;

        while (st <= en) {
            int mid = (st+en)/2;
            if(abs(a[i] + a[mid]) < abs(ans1+ans2)){
                ans1 = a[i];
                ans2 = a[mid];
            }

            if(a[i] + a[mid] < 0) st = mid+1;
            else if(a[i] + a[mid] > 0) en = mid-1;
            else{
                cout << 0;
                return 0;
            }
        }
    }

    cout << ans1 + ans2;
}
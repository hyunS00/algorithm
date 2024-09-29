#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

using namespace std;

int n;
ll a[5005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    ll ans1 = 1e9+1;
    ll ans2 = 1e9+1;
    ll ans3 = 1e9+1;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            int st = j + 1;
            int en = n;
            while (st < en) {
                int mid = (st + en) / 2;
                ll sum = a[i] + a[j] + a[mid];
                if(abs(sum) < abs(ans1 + ans2 + ans3)){
                    ans1 = a[i];
                    ans2 = a[j];
                    ans3 = a[mid];
                }

                if(sum < 0) st = mid +1;
                else if(sum > 0) en = mid;
                else {
                    cout << ans1 << " " << ans2 << " " << ans3;
                    return 0;
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3;
}
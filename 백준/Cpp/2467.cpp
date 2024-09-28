#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll fluid[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> fluid[i];

    sort(fluid, fluid + n);

    ll ans1 = 1e9+1, ans2 = 1e9+1;
    ll minSum = 1e9+1 * 2;
    for(int i = 0; i < n-1; i++){
        int left = i + 1;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            ll sum = fluid[i] + fluid[mid];
            
            if(abs(sum) < abs(minSum)){
                minSum = sum;
                ans1 = fluid[i];
                ans2 = fluid[mid];
            }

            if(sum < 0){
                left = mid + 1;
            }
            else if(sum > 0){
                right = mid - 1;
            }
            else{
                cout << ans1 << " " << ans2 << endl;
                return 0;
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
}
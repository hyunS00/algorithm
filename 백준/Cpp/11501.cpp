#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
typedef long long ll;

int t;
ll stock[1000000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> stock[i];
        
        ll ans = 0;
        int mx = stock[n-1];
        for(int i = n-2; i >= 0; i--){
            if(mx > stock[i])
                ans += mx - stock[i];
            else
                mx = stock[i];
        }
        cout << ans << endl;
    }
}
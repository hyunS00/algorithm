#include<iostream>
#define endl "\n"

using namespace std;
typedef long long ll;

ll recursive(ll a, ll b, ll c);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int a,b,c;
    cin >> a >> b >> c;

    ll ans = recursive(a, b, c);

    cout << ans << endl;
}

ll recursive(ll a, ll b, ll c){
   if(b == 1) return a % c;
   ll val = recursive(a, b/2, c);
   val = val * val % c;
   if(b%2 == 0) return val;
   return val * a % c;
}

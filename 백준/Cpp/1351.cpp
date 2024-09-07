#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

ll n, p, q;
map< ll, ll> M;

ll func(ll a){
    if(a == 0)
        return 1;
    
    if(M[a] != 0) return M[a];

    return  M[a] = func(a/p) + func(a/q);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p >> q;

    M[0] = 1 ;

    cout << func(n) << endl;
}
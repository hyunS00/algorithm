#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int t, n, m;
ll a[10010];
ll b[10010];
vector<ll> vec1;
vector<ll> vec2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }

    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        b[i] += b[i-1];
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < i; j++)
            vec1.push_back(a[i] - a[j]);

    for(int i = 1; i <= m; i++)
        for(int j = 0; j < i; j++)
            vec2.push_back(b[i] - b[j]);

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    ll cnt = 0;
    for(int i = 0; i < vec1.size(); i++){
        ll x = t - vec1[i];
        auto lb = lower_bound(vec2.begin(), vec2.end(), x);
        auto ub = upper_bound(vec2.begin(), vec2.end(), x);

        cnt += ub - lb;
    }

    cout << cnt;
}
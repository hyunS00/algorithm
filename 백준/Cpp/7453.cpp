#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n;
ll a[4001], b[4001], c[4001], d[4001];
vector<ll> two1;
vector<ll> two2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            two1.push_back(a[i] + b[j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            two2.push_back(c[i] + d[j]);
    
    sort(two2.begin(), two2.end());

    ll cnt = 0;
    for(int i = 0; i < (int)two1.size(); i++){
        auto lb = lower_bound(two2.begin(), two2.end(), -two1[i]);
        auto ub = upper_bound(two2.begin(), two2.end(), -two1[i]);

        cnt += ub - lb; 
    }

    cout << cnt << endl;
}
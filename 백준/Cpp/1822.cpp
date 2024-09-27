#include<iostream>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;
typedef long long ll;
const int LIMIT = 500000;

int n, m;

ll a[LIMIT], b[LIMIT];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    vector<ll> ans;
    for(int i = 0; i < n; i++)
        if(!binary_search(b, b + m, a[i]))
            ans.push_back(a[i]);

    cout << ans.size() << endl;

    for(auto i : ans)
        cout << i << " ";
}
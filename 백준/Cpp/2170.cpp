#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
pair<ll, ll> line[1000000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> line[i].first >> line[i].second;

    sort(line, line + n);

    ll ans = 0;
    int i = 0;
    while (i < n) {
        ll start = line[i].first;
        ll lastEnd = line[i].second;
        int j = i+1;
        while ( j < n && line[j].first <= lastEnd) {
            if(lastEnd < line[j].second)
                lastEnd = line[j].second;
            j++;
        }
        ans += lastEnd - start;
        i = j;
    }
    
    cout << ans << endl;
}
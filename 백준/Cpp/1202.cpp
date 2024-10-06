#include<iostream>
#include<set>
#include<tuple>
#include<algorithm>
using namespace std;
typedef long long ll;

int n, k;
pair<int, int> jewel[300005];
multiset<int> bag;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> jewel[i].second >> jewel[i].first;

    for(int i = 0; i < k; i++){
        int w;
        cin >> w;
        bag.insert(w);
    }
    sort(jewel, jewel+n);
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        int w, c;
        tie(c, w) = jewel[i];
        auto it = bag.lower_bound(w);
        if(it == bag.end()) continue;
        ans += c;
        bag.erase(it);
    }
    cout << ans;
}
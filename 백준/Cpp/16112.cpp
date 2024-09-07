#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, k;
vector<int> quest;
int stone[300001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i< n; i++){
        int exp;
        cin >> exp;
        quest.push_back(exp);
    }

    sort(quest.begin(), quest.end(), greater<int>());

    ll ans = 0;
    for(int i = 0; i < k; i++){
        int exp = quest.back(); quest.pop_back();
        ans += i * exp;
    }

    while (!quest.empty())
    {
        int exp = quest.back(); quest.pop_back();
        ans += k * exp;
    }
    
    cout << ans;
}
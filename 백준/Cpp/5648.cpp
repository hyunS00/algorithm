#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    vector<ll> reversed_numbers;
    reversed_numbers.reserve(n);
    
    while(n--){
        ll num;
        cin >> num;
        ll rev = 0;
        while(num > 0){
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        reversed_numbers.push_back(rev);
    }
    
    sort(reversed_numbers.begin(), reversed_numbers.end());
    
    string output;
    for(auto num : reversed_numbers){
        output += to_string(num) + '\n';
    }
    cout << output;
    
    return 0;
}

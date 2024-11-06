#include<iostream>
#include<stack>
#define H first
#define X second
#define endl "\n"
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
        int n;
        cin >> n;
        if(n == 0) return 0;
 
        stack<pair<ll, ll>> S;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int h;
            cin >> h;
            int idx = i;
            while(!S.empty() && S.top().H >= h){
                ans = max(ans, S.top().H * (i-S.top().X));
                idx = S.top().X;
                S.pop();
            }
            S.push({h, idx});
        }
        while(!S.empty()){
            ans = max(ans, S.top().H * (n-S.top().X));
            S.pop();
        }
        cout << ans << endl;
    }
}
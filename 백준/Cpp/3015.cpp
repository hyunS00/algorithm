#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;

int n;
int a[500005];
stack<int> S;
unordered_map<int,int> um;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    S.push(a[0]);
    for(int i = 1; i < n; i++){
        while(!S.empty() && S.top() < a[i]){
            ans++;
            um[S.top()] = 0;
            S.pop();
        }
        if(S.empty()){
            S.push(a[i]);
            continue;
        }

        um[a[i]]++;
        if(S.top() == a[i]){
            ans += um[a[i]];
        }
        else{
            ans++;
        }
        S.push(a[i]);
    }
    cout << ans;
}
#include<iostream>
#include<stack>
#include<tuple>
using namespace std;

int n, ans, num, a, t;
stack<pair<int, int>> S;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    while(n--){
        cin >> num;
        if(num == 1){
            cin >> a >> t;
            S.push({a, t});
        }

        if(S.empty()) continue;

        tie(a, t) = S.top(); S.pop();
        t--;
        if(t == 0) ans += a;
        else S.push({a, t});
    }

    cout << ans;
}
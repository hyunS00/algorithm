#include<iostream>
#include<stack>
#define endl "\n"

typedef long long ll;

using namespace std;

int N;
ll ans;
stack<int> s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    while (N--)
    {
        ll h;
        cin >> h;

        while(!s.empty() && s.top() <= h)
            s.pop();
        ans += s.size();
        s.push(h);
    }
    
    cout << ans << endl;
}
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int n, cnt = 0;
int a[100005];
int f[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int st = 0;
    ll cnt = 0;

    for(int en = 0; en < n; en++){
        f[a[en]]++;

        while (f[a[en]] > 1) {
            f[a[st]]--;
            st++;
        }
        cnt += en - st +1;
    }

    cout << cnt;
}
#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
const int LIMIT = 20000;


int t;
int a[LIMIT], b[LIMIT];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);

        int ans = 0;
        int idx = m-1;
        for(int i = n-1; i >= 0; i--){
            while (idx >= 0 && a[i] <= b[idx]) idx--;
            ans += idx + 1;
        }
        cout << ans << endl;
    }
    
}
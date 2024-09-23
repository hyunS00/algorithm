#include<iostream>
#include<algorithm>

using namespace std;

int n;
int p[1000];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    
    sort(p, p+n);

    int num = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        num += p[i];
        ans += num;
    }

    cout << ans << endl;
}
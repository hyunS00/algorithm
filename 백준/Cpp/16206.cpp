#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a[1005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >>a[i];

    sort(a, a+n);

    int cnt = 0;
    int cut = 0;
    for(int i = 0; i < n; i++){
        int len = a[i];
        if(len %10 != 0) continue;

        while (len > 10 && cut < m) {
            len -= 10;
            cnt++;
            cut++;
        }

        if(len == 10)
            cnt++;
    }

    for(int i = 0; i < n; i++){
        int len = a[i];
        if(len %10 == 0) continue;

        while (len > 10 && cut < m) {
            len -= 10;
            cnt++;
            cut++;
        }

        if(len == 10)
            cnt++;
    }

    cout << cnt;
}
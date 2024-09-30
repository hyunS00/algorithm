#include<iostream>
using namespace std;

int n, k, mx;
int s[1000005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    int st = 0;
    int erase = 0;
    int cnt = 0;
    for(int en = 0; en < n; en++){
        if(s[en]%2 == 0) cnt++;
        else erase++;

        while (st < en && erase > k) {
            if(s[st]%2 == 0) cnt--;
            else erase--;
            st++;
        }
        
        mx = max(mx, cnt);
    }
    
    cout << mx;
}
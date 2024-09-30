#include<iostream>
using namespace std;

int n, k;
int a[200005];
int freq[100005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for(int i = 0; i <n; i++)
        cin >> a[i];
    
    int st = 0;
    int mx = 0;
    for(int en = 0; en < n; en++){
        freq[a[en]]++;
        while(freq[a[en]] > k) freq[a[st++]]--;
        mx = max(mx, en-st+1);
    }

    cout << mx;
}
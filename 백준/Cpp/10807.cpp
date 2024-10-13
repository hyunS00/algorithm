#include<iostream>
using namespace std;
int n, v, ans;
int arr[100];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> v;
    for(int i = 0; i < n; i++)
        if(arr[i] == v) ans++;
    
    cout << ans;
}
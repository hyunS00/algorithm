#include<iostream>
using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    string ans = "CY";
    if(n%2 == 0)
        ans = "SK";
    
    cout << ans;
}
#include<iostream>
using namespace std;

int n, k = 1;
int num[500005];
void solve(){
    for(int i = 2; i <= n; i++){
        if(num[i] > 0) continue;
        k++;
        for(int j = i; j <= n; j += i){
            num[j] = k;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    num[1] = k;
    solve();
    cout << k << endl;
    for(int i = 1; i <= n; i++)
        cout << num[i] << " ";
}
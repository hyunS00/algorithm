#include<iostream>
#include<algorithm>
using namespace std;

int n;
int book[300005];
int sorting[300005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> book[i];
        sorting[i] = book[i];
    }

    sort(sorting, sorting+n);

    int fix_idx = n-1;
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(sorting[fix_idx] == book[i]){
            cnt++;
            fix_idx--;
        }
    }

    cout << n-cnt;
}
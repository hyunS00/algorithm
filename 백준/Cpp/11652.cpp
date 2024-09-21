#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
int n;

ll arr[100000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);


    int cnt = 1;
    ll num = arr[0];
    ll ans;
    int mx = 0;
    for(int i = 1; i < n; i++){
        if(num == arr[i]){
            cnt++;
        }
        else{
            if(cnt > mx){
                mx = cnt;
                ans = num;
            }
            num = arr[i];
            cnt = 1;
        }
    }

    if(cnt > mx){
        ans = num;
    }

    cout << ans << endl;
}
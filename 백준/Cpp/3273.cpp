#include<iostream>
#define endl "\n"
#define MAX_A 1000000
#define MAX_X 2000000

using namespace std;

int n, a[MAX_A], nums[MAX_X], x, cnt;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        nums[a[i]] = 1;
    }
    
    cin >> x;

    for(int i = 0; i < n; i++){
        if(nums[x-a[i]]) cnt++;
    }

    cout << cnt/2 << endl;
}
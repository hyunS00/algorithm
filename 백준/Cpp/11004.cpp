#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
vector<int> a;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    while(n--){
        int num;
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());
    cout << a[k-1];
}
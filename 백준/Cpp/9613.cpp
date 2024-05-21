#include<iostream>
#include<vector>
using namespace std;

int t, n;
vector<int> num(100);

int gcd(int x, int y);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> n;
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> num[i];
        }

        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                cnt += gcd(num[i], num[j]);
            }
        }
        cout << cnt <<"\n";
    }
}

int gcd(int x, int y){
    if(y == 0) return x;

    return gcd(y, x % y);
}
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> tile(1001);

int main(){
    cin >> n;

    tile[1] = 1;
    tile[2] = 3;
    for(int i = 3; i <= n; i++){
        tile[i] = (2*tile[i-2] + tile[i-1])%10007;
    }

    cout << tile[n] << "\n";
}
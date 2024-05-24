#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> tile(1001);

int main() {
    cin >> n;

    tile[0] = 1;
    tile[1] = 1;
    for(int i = 2; i <= n; i++){
        tile[i] = (tile[i-2]%10007 + tile[i-1]%10007)%10007;
    }

    cout << tile[n] << "\n";
}
#include<iostream>
#include<vector>
using namespace std;

int T, n;
vector<int>num(11);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;

    for(int i = 4; i < 11; i++){
        num[i] = num[i-3] + num[i-2] + num[i-1];
    }

    while (T--)
    {
        cin >> n;
        cout << num[n] << "\n";
    }
    
}
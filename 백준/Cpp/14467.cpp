#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, ans = 0;
    cin >> n;

    int cows[n];
    fill(cows, cows+n+1, -1);

    while (n--)
    {
        int num, position;
        cin >> num >> position;

        if(cows[num] == -1){
            cows[num] = position;
        }else if(cows[num] != position){
            ans++;
            cows[num] = position;
        }else{
            cows[num] = position;
        }
    }
    cout << ans << endl;
}
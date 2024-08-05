#include<iostream>
#define endl "\n"
#define MAX_N 1000000

using namespace std;

int n,counts[11],maxCnt = 0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while(n){
        int num = n % 10;
        n /= 10;

        if(num==6 && counts[6] > counts[9]) num = 9;
        if(num==9 && counts[6] < counts[9]) num = 6;
        maxCnt = max(maxCnt, ++counts[num]);
    }

    cout << maxCnt << endl;
}
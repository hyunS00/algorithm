#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int N, sum=0;
    string strNum;
    cin >> N >> strNum;
    for(int i=0;i<N;i++){
        sum += strNum[i]-48;
    }
    cout << sum << endl;
}
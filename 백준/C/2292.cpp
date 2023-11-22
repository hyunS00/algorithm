#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int N;
    cin >> N;
    int sum=1;
    int level=0;
    while (sum<N)
    {
        sum += 6*level;
        level++;
    }

    if(N==1){
        cout << 1 << endl;
    }else{
        cout << level << endl;
    }
}
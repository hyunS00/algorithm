#include <bits/stdc++.h>
using namespace std;

int numCnt [10001];

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int N,num;
    cin >> N;
    while (N--)
    {
        cin >> num;
        numCnt[num]++;
    }

    for(int i=1;i<10001;i++){
        if(numCnt[i]) {
            for(int j=0;j<numCnt[i];j++){
                cout << i << endl;
            }
        }
    }
}
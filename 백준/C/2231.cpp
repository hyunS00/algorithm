#include <bits/stdc++.h>
using namespace std;

int solved(int N){
    for(int i=1; i <= N; i++){
        int base = i;
        int sum = base;
        while(base){
            sum += base % 10;
            base /= 10;
        }

        if(sum == N) return i;
    }

    return 0;
}

int main(){
    int N;
    cin >> N;

    int ans = solved(N);

    cout << ans << "\n";
}
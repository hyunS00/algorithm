#include<iostream>
#define endl "\n"
using namespace std;

int t;
bool notPrime[100005];
bool mulPrime[100005];

int solve(int k){
    for(int i = k; i <= 100001; i++){
        if(mulPrime[i]) return i;
    }
    return -1;
}

void getMulPrime(){
    for(int i = 2; i < 100000; i++){
        if(notPrime[i]) continue;
        for(int j = i+1; j <= 100000; j++){
            if(notPrime[j])continue;
            int mul = i * j;
            if(mul > 100005 || mul  <= 0) break;
            mulPrime[mul] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i = 2; i*i <= 100000; i++){
        if(notPrime[i]) continue;
        for(int j = i*i; j <= 100000; j+=i){
            notPrime[j] = true;
        }
    }

    getMulPrime();

    cin >> t;
    while (t--) {   
        int k;
        cin >> k;

        cout << solve(k) << endl;
    }   
}
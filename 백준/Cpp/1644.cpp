#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int state[4000005];
vector<int> prime;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 2; i <= n; i++){
        if(state[i]) continue;
        prime.push_back(i);
        for(int j = i; j <= n; j += i)
            state[j] = true;
    }

    int en = 0;
    int tot = prime[0];
    int cnt = 0;
    for(int st = 0; st < prime.size(); st++){
        while (en < prime.size() && tot < n){
            en++;
            if(en != prime.size()) tot += prime[en];
        }
        if(en == prime.size()) break;
        if(tot == n) cnt++;
        tot -= prime[st];
    }
    cout << cnt;
}
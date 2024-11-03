#include<iostream>
using namespace std;

int n;
bool isPrime[1000005];

bool isPal(int num){
    string s = to_string(num);
    int st = 0;
    int en = s.size()-1;
    while (st < en) {
        if(s[st] != s[en]) return false;
        st++;
        en--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    fill(isPrime, isPrime+1000005, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i < 1000005; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j < 1000005; j += i){
            isPrime[j] = false;
        }
    }

    for(int i = n; i < 2000000; i++){
        if(isPrime[i] && isPal(i)){
            cout << i;
            return 0;
        }
    }
}
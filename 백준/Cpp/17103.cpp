#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int T, N;
vector<int> prime(1000001, 1);

void get_prime_number();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    get_prime_number();

    while (T--)
    {
        cin >> N;
        int cnt = 0;
        for(int i = 2 ; i <= N/2; i++){
            if(prime[i] && prime[N-i])
                cnt++;
        }
        cout << cnt << "\n";
    }
}

void get_prime_number(){
    int end = sqrt(1000001);
    for(int i = 2; i < end; i ++){
        if(!prime[i])
            continue;
        for(int j = i * 2; j < 1000001; j += i){
            prime[j] = 0;
        }
    }
}
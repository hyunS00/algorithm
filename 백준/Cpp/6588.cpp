#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n;
vector<int> prime(1000001, 1);
void get_prime();
void goldbachs_conjecture(int find);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    get_prime();

    cin >> n;
    while (n != 0){
        goldbachs_conjecture(n);
        cin >> n;
    }
}

void get_prime(){
    int en = sqrt(1000001);
    prime[0] = 0;
    prime[1] = 0;

    for(int i = 2; i <= en; i++){
        if(prime[i] == 0)
            continue;
        for(int j = i * i; j < 1000001; j += i){
            prime[j] = 0;
        }
    }
}

void goldbachs_conjecture(int find){
    for(int i = 2; i <= find / 2; i++){
        if(prime[i] && prime[find - i]){
            cout << find << " = " << i << " + " << find-i << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << "\n";
}
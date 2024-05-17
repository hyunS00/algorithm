#include<iostream>
#include<vector>
using namespace std;

int M, N;
vector<int> prime_number(1000001, 1);
void get_prime_number(int end);

int main(){
    cin >> M >> N;
    get_prime_number(N);

    for(int i = M; i <= N; i++){
        if(prime_number[i])
            cout << i << "\n";
    }
}

void get_prime_number(int end){
    prime_number[1] = 0;
    for(int i = 2; i <= end; i++){
        if(prime_number[i] == 0)
            continue;
        
        for(int j = 2*i; j <= end; j+=i){
            prime_number[j] = 0;
        }
    }
}
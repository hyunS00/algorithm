#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N, S;
vector<int> A(100000);

int GCD(int x, int y);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> S;

    for(int i = 0; i< N; i++){
        cin >> A[i];
        A[i] = abs(A[i]- S);
    }

    int gcd = A[0];

    for(int i = 1; i < N; i++){
        gcd = GCD(gcd, A[i]);
    }
    
    cout << gcd <<"\n";
}

int GCD(int x, int y){
    if(y == 0) return x;

    return GCD(y, x%y);
}
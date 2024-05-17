#include<iostream>
using namespace std;

int gcd(int a, int b);
void swap(int *a, int *b);
int a, b;

int main(){
    int mcm, mcd;
    cin >> a >> b;
    mcd = gcd(a, b);
    mcm = a * b / mcd;
    cout << mcd << " " << mcm << "\n";
}

int gcd(int a, int b){
    if(a < b)
        swap(&a, &b);
    int tmp;
    while (a % b)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
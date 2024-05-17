#include<iostream>
using namespace std;

int T, A, B;

void swap(int *a, int *b);
int gcd(int a, int b);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int min_common_mul;

    while (T--) {
        cin >> A >> B;
        min_common_mul = gcd(A, B);

        cout << A * B /min_common_mul << "\n";
    }
}

int gcd(int a, int b) {
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

void swap(int *a, int *b) {
    if(*a > *b)
        return;

    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int n;
string serial[50];

int digitSum(const string &s){
    int sum = 0;
    for(auto c : s){
        if(c <= '9')
            sum += c-'0';
    }
    return sum;
};

bool cmp(const string &A, const string &B){
    if(A.size() != B.size())
        return A.size() < B.size();

    int sumA = digitSum(A);
    int sumB = digitSum(B);
    if(sumA != sumB)
        return sumA < sumB;
    
    return A < B;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> serial[i];

    sort(serial, serial+n, cmp);

    for(int i = 0; i < n; i++)
        cout << serial[i] << endl;
}
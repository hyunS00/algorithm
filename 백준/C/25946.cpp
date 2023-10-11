
#include <bits/stdc++.h>
using namespace std;

long Solve(long n, long a, long b, vector<long> present);

int main(){
    long n,b,a;
    cin >> n >> b >> a;
    vector<long> present(n);
    for(auto it = present.begin(); it != present.end(); it++){
        cin >> (*it);
    }

    cout << Solve(n,a,b,present) << endl;

    return 0;
}

long Solve(long n, long a, long b, vector<long> present){
    long left=0,right=0,sum=0;

    sort(present.begin(),present.end());

    while (right<a)
    {
        sum += present[right]/2;
        if(sum>b){
            return right;
        }
        ++right;
    }

    while (right<n)
    {
        sum += present[right++]/2;
        sum += present[left++]/2;
        if(sum >b){
            return right;
        }
        ++right;
    }
    return right;
}
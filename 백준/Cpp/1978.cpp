#include<bits/stdc++.h>
using namespace std;

int N, cnt, num;
bool is_prime(int num);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> num;
        if(is_prime(num))
            cnt++;
    }
    cout << cnt << "\n";
}

bool is_prime(int num) {
    if (num == 2)
        return 1;
    if (num % 2 == 0 || num < 2)
        return 0;

    for(int i = 3; i < num; i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}
#include<iostream>
using namespace std;

int p, q, a, n, ans;
void func(int nume, int deno, int start, int cnt){
    if(cnt > n) return;
    if(deno * p == nume * q){
        ans++;
        return;
    }
    for(int i = start; i*deno <= a; i++){
        int nextNume = deno + i * nume;
        int nextDeno = deno * i;
        func(nextNume, nextDeno, i, cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> p >> q >> a >> n;
    func(0, 1, 1, 0);

    cout << ans;
}
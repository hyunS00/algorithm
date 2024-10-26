#include<iostream>
using namespace std;

int a, b, c;
int truck[101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        int s, e;
        cin >> s >> e;
        for(int j = s; j < e; j++) truck[j]++;
    }

    int sum = 0;
    for(int i = 1; i <= 100; i++){
        if(truck[i] == 1) sum += a;
        else if(truck[i] == 2) sum += b*2;
        else if(truck[i] == 3) sum += c*3;
    }

    cout << sum;
}
#include<iostream>
#define endl "\n"

using namespace std;

int n, t, p;
int tSize[6];
int tBundle, pBundle, pencil;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < 6; i++)
        cin >> tSize[i];
    cin >> t >> p;

    for(int i = 0; i < 6; i++){
        tBundle += tSize[i] / t;
        if(tSize[i] % t != 0) tBundle++;
    }

    pBundle = n / p;
    pencil = n % p;

    cout << tBundle << endl;
    cout << pBundle << " " << pencil << endl;
}
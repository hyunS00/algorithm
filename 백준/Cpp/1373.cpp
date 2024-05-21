#include<iostream>
using namespace std;

string binary;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> binary;

    while (binary.length() % 3 != 0)
    {
        binary = '0' + binary;
    }

    for(int i = 0; i < binary.length(); i += 3){
        int num = (binary[i]-'0') * 4 + (binary[i+1] - '0') * 2 + (binary[i+2] - '0');
        cout << num;
    }
    cout << "\n";
}
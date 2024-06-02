#include<iostream>
#include<string>
using namespace std;

string octal;

string binary[10] = {"000", "001", "010", "011", "100", "101", "110", "111"};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> octal;
    for(int i = 0; i < octal.length(); i++){
        int num = octal[i] - '0';
        if(i == 0)
            cout << stoi(binary[num]);
        else
            cout << binary[num];
    }
    cout << "\n";
}
#include<iostream>
#define endl "\n";

using namespace std;

string odd;
string even;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> odd >> even;

    for(int i = 0; i < odd.length(); i++) {
        if(i >= even.length())
            break;
        
        if(i % 2 == 0)
            cout << odd[i];
        else
            cout << even[i];
    }
    cout << endl;
}
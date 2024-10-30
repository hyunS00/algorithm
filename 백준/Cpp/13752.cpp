#include<iostream>
using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        string s = "";
        for(int i = 0; i < k; i++)
            s += "=";
        cout << s << endl;
    }
}
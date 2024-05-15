#include<iostream>
using namespace std;

string line, ans;

int main(){
    getline(cin, line);

    for(int i : line){
        int shift = i + 13;
        if(i >= 97){
            if(shift > 122){
                shift -= 26;
            }
            ans += (char) shift;
        }
        else if (i >= 65){
            if (shift > 90){
                shift -=26;
            }
            ans += (char) shift;
        }
        else {
            ans += (char) i;
        }
    }

    cout << ans << "\n";
}
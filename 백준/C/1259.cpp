#include <bits/stdc++.h>
using namespace std;

int main(){
    int input;
    do{
        cin >> input;
        if (input == 0) return 0;
        if(input % 10 != 0){
            int reverseNum = 0;
            int copyInput = input;
            while(copyInput){
                reverseNum = reverseNum * 10;
                reverseNum += copyInput % 10;
                copyInput = copyInput/10;
            }
            if(input == reverseNum){
                cout << "yes" << endl;
                continue;
            }
        }
        cout << "no" << endl;
    } while (input);
}
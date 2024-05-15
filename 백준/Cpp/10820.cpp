#include<iostream>
#include<vector>
using namespace std;

int small, big, num, space;
string line;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(getline(cin, line)){
        small = 0;
        big = 0;
        num = 0;
        space = 0;

        for(int i : line){
            if(i >= 97)
                small++;
            else if(i >= 65)
                big++;
            else if(i >= 48)
                num++;
            else
                space++;
        }
        cout << small << " " << big << " " << num << " " << space << "\n";
    }
}
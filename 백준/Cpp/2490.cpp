#include<iostream>
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    for(int i = 0; i < 3; i++){
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            int yoot;
            cin >> yoot;
            cnt += yoot;
        }

        if(cnt >= 4){
            cout << "E" << endl;
        }
        else if(cnt == 3){
            cout << "A" << endl;
        }
        else if(cnt == 2){
            cout << "B" << endl;
        }
        else if( cnt == 1){
            cout << "C" << endl;
        }
        else{
            cout << "D" << endl;
        }
    }
}
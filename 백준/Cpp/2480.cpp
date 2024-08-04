#include<iostream>
#define endl "\n"

using namespace std;

int dice[3];
int money;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    for(int i = 0; i < 3; i++){
        cin >> dice[i];
    }

    if(dice[0] == dice[1] && dice[0] == dice[2] && dice[1] == dice[2]){
        money = 10000 + dice[0] * 1000;
    }
    else if(dice[0] == dice[1]){
        money = 1000 + dice[0] * 100;
    }
    else if(dice[0] == dice[2]){
        money = 1000 + dice[0] * 100;
    }
    else if(dice[1] == dice[2]){
        money = 1000 + dice[1] * 100;
    }
    else{
        int max_value = 0;

        max_value = max(dice[0],dice[1]);
        max_value = max(max_value,dice[2]);

        money = max_value * 100;
    }

    cout << money << endl;
}
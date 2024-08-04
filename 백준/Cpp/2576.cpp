#include<iostream>
#define endl "\n"
#define MAX 100

using namespace std;

int sum,min_value = MAX;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i = 0 ; i < 7; i++){
        int num;
        cin >> num;

        if(num % 2 != 0){
            sum += num;
            min_value = min(min_value, num);
        }
    }

    if(min_value >= 100){
        cout << -1 << endl;
    }
    else{
        cout << sum << endl << min_value << endl;
    }
}
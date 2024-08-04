#include <iostream>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int y = 0, m = 0;
    for(int i = 0; i < n; i++){
        int time;
        cin >> time;

        y += (time / 30 + 1) * 10;
        m += (time /60 + 1) * 15;
    }

    if(y > m){
        cout << "M " << m << endl;
    }
    else if (y < m){
        cout << "Y " << y << endl;
    }
    else{
        cout << "Y M " << y << endl;
    }
}
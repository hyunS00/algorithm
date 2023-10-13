#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    string H, W, N;
    cin >> T;

    for(int i=0; i< T;i++){
        cin >> H >> W >> N;
        int numH = stoi(H);
        int numN = stoi(N);

        int h = numN % numH;
        int w = numN / numH;

        if(h <=0){
            h = numH;
            
        }else{
            w++;
        }
        h *= 100;

        cout << h+w << endl;
    }
}
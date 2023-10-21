#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> movieNum;
    int digit = 1;
    int digitCnt = 0;
    int N;
    cin >> N; 
    for(int i = 1; movieNum.size()<N; i++){
        if(i % digit == 0){
            digit *= 10 ;
            ++ digitCnt;
        }

        int digitTen = 1;
        for(int j = 1 ;j < digitCnt -2 + 1; j++){
            digitTen *= 10;
            if((i - (666*digitTen/10)) % (digitTen*100) < digitTen/10 && (i - (666*digitTen/10)) >=0){
                movieNum.push_back(i);
                break;
            } 
        }
    }
    cout << movieNum[N-1] << endl;
}
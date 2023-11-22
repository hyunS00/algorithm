#include <bits/stdc++.h>
using namespace std;

bool cmp (pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}

int main(){
    int A,B,C,startTiem,endTime;
    vector<pair<int,int>> times;
    vector<int> price;
    cin >> A >> B >> C;

    price.push_back(A);
    price.push_back(B);
    price.push_back(C);

    for(int i=0;i<3; i++){
        cin >> startTiem >> endTime;
        times.push_back({startTiem,endTime});
    }
    sort(times.begin(),times.end(),cmp);

    int totalPrice = 0;
    for(int i=0;i<3;i++){
        totalPrice += (times[i].second - times[i].first)*price[i];
    }
    cout << totalPrice;
}
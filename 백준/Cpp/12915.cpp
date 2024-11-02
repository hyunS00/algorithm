#include<iostream>
using namespace std;

int p[5];

bool solve(int mid){
    int needE = max(0, mid - p[0]);
    int needM = max(0, mid - p[2]);
    int needH = max(0, mid - p[4]);

    if(p[1] < needE) return false;

    int left_EM = p[1] - needE;

    if(p[3] < needH) return false;
    int left_MH = p[3] - needH;

    if(left_EM + left_MH < needM) return false;

    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 5; i++)
        cin >> p[i];
    
    int st = 0;
    int en = p[0]+p[1]+p[2]+p[3]+p[4];
    while(st < en){
        int mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << en;
}
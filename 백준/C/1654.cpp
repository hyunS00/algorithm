#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> lans;
    long long K, N, num, lanCnt;
    long long first=1, mid=0, last=1;
    cin >> K >> N;
    lanCnt = K;
    for(long long i=0 ;i<K;i++){
        cin >> num;
        lans.push_back(num);
    }

    sort(lans.begin(),lans.end());
    last = lans[K-1];
    while(first<=last){
        lanCnt = 0;
        mid = (last + first)/2;
        if(!mid) break;
        for(long long i=0;i<K;i++){
            lanCnt += lans[i]/mid;
        }
        if(lanCnt<N){
            last = mid-1;
        }else{
            first = mid+1;
        }
    }
    cout << last << endl;
}
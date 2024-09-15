#include <iostream>
#include <queue>
using namespace std;

const int LIMIT_W = 100;

int n, w, l;
int bridge[LIMIT_W];
queue<int> DQ;

int lw, t;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w >> l;

    for(int i = 0; i < n; i++){
        int truck;
        cin >> truck;
        DQ.push(truck);
    }
    
    while (!DQ.empty() || lw > 0) {
        if(bridge[w-1] > 0){
            lw -= bridge[w-1];
        }

        for(int i = w-1; i > 0; i--){
            bridge[i] = bridge[i-1];
        }
        bridge[0] = 0;

        if(!DQ.empty() && lw + DQ.front() <= l){
            int truck = DQ.front(); DQ.pop();
            bridge[0] = truck;
            lw += truck;
        }
        t++;
    }
    
    cout << t << endl;
}
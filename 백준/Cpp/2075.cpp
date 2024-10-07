#include<iostream>
#include<queue>
using namespace std;

int n;
priority_queue<int> PQ;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            PQ.push(-num);

            if(PQ.size() > n) PQ.pop();
        }
    }
    cout << -PQ.top();
}
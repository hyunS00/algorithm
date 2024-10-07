#include<iostream>
#include<queue>
#define endl "\n"
using namespace std;

int n;
priority_queue< pair<int, int> > PQ;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        if(x == 0){ 
            if(PQ.empty()){
                cout << 0 << endl;
            }
            else{
                cout << -PQ.top().second << endl;
                PQ.pop();
            }
                
        }
        else PQ.push({-abs(x), -x});
    }
}
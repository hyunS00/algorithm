#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
#define endl "\n"
using namespace std;

int n, t;
// 우선순위, id, 시간
priority_queue<tuple<int, int, int>>PQ;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t >> n;
    while(n--){
        // id, 시간, 우선순위
        int a, b, c;
        cin >> a >> b >> c;
        PQ.push({c, -a, b});
    }

    int cnt = 1;
    while(!PQ.empty()){
        int c, a, b;
        tie(c, a, b) = PQ.top(); PQ.pop();
        a = -a;
        cout << a << endl;
        if(++cnt > t) return 0;
        b--;
        if(b > 0){
            c--;
            PQ.push({c, -a, b});
        }
    }
}
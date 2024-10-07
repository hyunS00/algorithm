#include<iostream>
#include<queue>
using namespace std;

int n;
priority_queue<int> PQ;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        PQ.push(-num);
    }

    int ans = 0;
    while (PQ.size() > 1)
    {
        int a = -PQ.top(); PQ.pop();
        int b = -PQ.top(); PQ.pop();
        PQ.push(-(a+b));
        ans += a+b;
    }
    
    cout << ans;
}
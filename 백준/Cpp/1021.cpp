#include <iostream>
#include <deque>
#include<algorithm>
#define endl "\n"

using namespace std;

int N, M, ans = 0;
deque<int> dq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) dq.push_back(i);
    
    while (M--)
    {
        int num;
        cin >> num;
        int idx = find(dq.begin(), dq.end(), num) - dq.begin();
        while (dq.front() != num) {
            if(idx < (int)dq.size() - idx){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans << endl;
}
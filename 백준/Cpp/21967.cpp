#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

int n;
int a[1000000];
deque<int> mn, mx;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    int st = 0;
    for(int en = 0; en < n; en++){
        while(!mn.empty() && a[mn.back()] >= a[en])
            mn.pop_back();
        mn.push_back(en);

        while(!mx.empty() && a[mx.back()] <= a[en])
            mx.pop_back();
        mx.push_back(en);

        while (a[mx.front()]-a[mn.front()] > 2) {
            st++;
            if(!mn.empty() && mn.front() < st)
                mn.pop_front();
            if(!mx.empty() && mx.front() < st)
                mx.pop_front();
        }
        ans = max(ans, en-st+1);
    }

    cout << ans;
}
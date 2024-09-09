#include<iostream>
#include<queue>
#define endl "\n"

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--)
    {
        priority_queue<int> PQ;
        queue< pair<int, int> > Q;
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            PQ.push(p);
            Q.push({p, i});
        }

        int sequence = 1;
        while (true) {
            while (Q.front().first != PQ.top()){
                Q.push(Q.front());
                Q.pop();
            }
            if(Q.front().second == m)
                break;
            PQ.pop();
            Q.pop();
            sequence++;
        }
        cout << sequence << endl; 
    }
}
#include<iostream>
#include<queue>

using namespace std;

int k, n;
int duration = 210;

queue<int> Q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> k >> n;

    for(int i = 1; i <= 8; i++)
        Q.push(i);
    
    while (Q.front() != k)
    {
        Q.push(Q.front());
        Q.pop();
    }

    while (n--)
    {
        int t;
        char z;
        cin >> t >> z;

        duration -= t;

        if(duration <= 0)
            break;
        
        if(z == 'T'){
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    cout << Q.front() << endl;
}
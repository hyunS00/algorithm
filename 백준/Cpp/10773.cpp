#include<iostream>
#include<stack>
#define MAX 1000000
#define endl "\n"

typedef long long ll;

using namespace std;

stack<int> S;
int k, sum;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> k;

    while (k--)
    {
        int num;
        cin >> num;

        if(num){
            sum += num;
            S.push(num);
        }
        else{
            if(!S.empty()){
                sum -= S.top();
                S.pop();
            }
        }
    }
    
    cout << sum << endl;
}
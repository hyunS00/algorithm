#include<iostream>
#include<stack>

using namespace std;

string formula;
stack<int> S;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> formula;

    for(auto c : formula){
        if(c == '*' || c == '+' || c == '-' || c == '/'){
            int op1 = S.top(); S.pop();
            int op2 = S.top(); S.pop();

            if(c == '*') op2 *= op1;
            else if(c == '/') op2 /= op1;
            else if(c == '+') op2 += op1;
            else if(c == '-') op2 -= op1;

            S.push(op2);
        }
        else{
            S.push(c - '0');
        }
    }
    int ans = S.top(); S.pop();

    cout << ans << endl;
}
#include<iostream>
#include<stack>
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    while (getline(cin,line) && line != ".")
    {
        stack<char> s;
        int balance = 1;
        for(auto c : line){
            if(c == '(' || c == '{' || c == '['){
                s.push(c);
            }
            else if(c == ')'){
                if(!s.empty() && s.top() == '(') {
                    s.pop();
                }else{
                    balance = 0;
                    break;
                }
            }
            else if(c == '}'){
                if(!s.empty() && s.top() == '{') {
                    s.pop();
                }else{
                    balance = 0;
                    break;
                }
            }
            else if(c == ']'){
                if(!s.empty() && s.top() == '[') {
                    s.pop();
                }else{
                    balance = 0;
                    break;
                }
            }
        }

        if(balance && s.empty()){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}
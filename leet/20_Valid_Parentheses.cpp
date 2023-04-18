#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<int>stack;
    char top;
    stack.push(s[0]);
    top=stack.top();
    for(int i=1;i<s.size();i++){
        stack.push(s[i]);
        if((stack.top()==')'&&top=='(')||(stack.top()=='}'&&top=='{')||(stack.top()==']'&&top=='[')){
            cout<< (char)stack.top()<< "pop\n";
            stack.pop();
            cout<< (char)stack.top()<< "pop\n";
            stack.pop();
            cout<< (char)stack.top()<< "\n";
            top=':';
        }
        if(!stack.empty()){
            top=stack.top();
            cout<< (char)top<<","<<i<<","<<"\n";
        }
    }
    if(stack.empty())
        return true;
    return false;

    // stack<char>stack;
    // char* top;
    // stack.push(s[0]);
    // top=(char*)stack.top();
    // for(int i=1;i<s.size();i++){
    //     stack.push(s[i]);
    //     if(((char*)stack.top()==")"&&top=="(")||((char*)stack.top()=="}"&&top=="{")||((char*)stack.top()=="]"&&top=="[")){
    //         stack.pop();
    //         stack.pop();
    //     }
    //     top=(char*)stack.top();
    // }
    // if(stack.empty())
    //     return true;
    // return false;
}

int main(){
    string input = "()";
    bool result = isValid(input);
    cout<<result<<'\n';
}
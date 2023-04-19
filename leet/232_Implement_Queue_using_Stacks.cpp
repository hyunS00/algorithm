#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        if(popStack.empty()){
            while (!pushStack.empty())
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        if(popStack.empty())
            return 0;
        int value = popStack.top();
        popStack.pop();
        return value;
    }
    
    int peek() {
        if(popStack.empty()){
            while (!pushStack.empty())
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        if(popStack.empty())
            return 0;
        return popStack.top();
    }
    
    bool empty() {
        if(pushStack.empty()&&popStack.empty())
            return true;
        return false;
    }
    stack<int>pushStack;
    stack<int>popStack;
};

int main (){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 =obj->peek();
    int param_3 =obj->pop();
    bool param_4=obj->empty();
    cout << param_2 << ','<< param_3 <<','<< param_4<<'\n'; 
}
#include<iostream>
#include<stack>
using namespace std;

void push_front(int x);
void push_back(int x);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

int N, x;
string com;
stack<int> fs, bs;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> com;
        if(com == "push_front"){
            cin >> x;
            push_front(x);
        }
        else if(com == "push_back"){
            cin >> x;
            push_back(x);
        }
        else if(com == "pop_front"){
            cout << pop_front() << "\n";
        }
        else if(com == "pop_back"){
            cout << pop_back() << "\n";
        }
        else if(com == "size"){
            cout << size() << "\n";
        }
        else if(com == "empty"){
            cout << empty() << "\n";
        }
        else if(com == "front"){
            cout << front() << "\n";
        }
        else if(com == "back"){
            cout << back() << "\n";
        }
    }
}

void push_front(int x){
    fs.push(x);
}

void push_back(int x){
    bs.push(x);
}

int pop_front(){
    int pop;
    
    if(fs.empty()){
        if(bs.empty())
            return -1;
        
        while (!bs.empty())
        {
            fs.push(bs.top());
            bs.pop();
        }
    }
    pop = fs.top();
    fs.pop();
    return pop;
}

int pop_back(){
    int pop;
    
    if(bs.empty()){
        if(fs.empty())
            return -1;
        
        while (!fs.empty())
        {
            bs.push(fs.top());
            fs.pop();
        }
    }
    pop = bs.top();
    bs.pop();
    return pop;
}

int size(){
    return fs.size() + bs.size();
}

int empty(){
    return 0 == size();
}

int front(){
     if(fs.empty()){
        if(bs.empty())
            return -1;
        
        while (!bs.empty())
        {
            fs.push(bs.top());
            bs.pop();
        }
    }
    return fs.top();
}

int back(){
    if(bs.empty()){
        if(fs.empty())
            return -1;
        
        while (!fs.empty())
        {
            bs.push(fs.top());
            fs.pop();
        }
    }
    return bs.top();
}
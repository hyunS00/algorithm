#include<iostream>
#include<stack>
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    getline(cin, line);

    stack<char> s;
    int sum = 0;
    int mul = 1;
    int tmp = 1;

    for(int idx = 0; idx < (int)line.length(); idx++){
        if(line[idx] == ')'){
            if(s.empty()) {
                mul = 0;
                tmp = 0;
                sum = 0;
                break;
            }
            else if(s.top() == '['){
                mul = 0;
                tmp = 0;
                sum = 0;
                break;
            }

            tmp *= 2;
            mul /= 2;
            s.pop();
        }
        if(line[idx] == ']'){
            if(s.empty()) {
                mul = 0;
                tmp = 0;
                sum = 0;
                break;
            }
            else if(s.top() == '('){
                mul = 0;
                tmp = 0;
                sum = 0;
                break;
            }

            tmp *= 3;
            mul /= 3;
            s.pop();
        }
        else if(line[idx] == '('){
            if(line[idx-1] == ')' || line[idx-1] == ']'){
                tmp *= mul;
                sum += tmp;
                tmp = 1;
            }
            mul *= 2;
            s.push('(');
        }
        else if(line[idx] == '['){
            if(line[idx-1] == ')' || line[idx-1] == ']'){
                tmp *= mul;
                sum += tmp;
                tmp = 1;
            }
            mul *= 3;
            s.push('[');
        }
    }

    if(s.empty()){
        sum += tmp * mul;
    }
    else{
        sum = 0;
    }

    cout << sum << endl;
}
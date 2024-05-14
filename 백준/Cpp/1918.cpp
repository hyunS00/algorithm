#include<iostream>
#include<vector>
using namespace std;

int get_op_priority(char oper);

string expression, ans;
char op1, op2;
vector<char> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> expression;

    for (char i : expression){
        if(i == '('){
            s.push_back(i);
        }
        else if (i == ')') {
            while (!s.empty()) {
                if(s.back() == '(') {
                    s.pop_back();
                    break;
                }
                op1 = s.back();
                s.pop_back();
                ans += op1;
            }
        }
        else if(i == '+' || i == '-' || i == '*' || i == '/'){
            if(s.empty()) {
                s.push_back(i);
            }
            else 
            {
                while(!s.empty() &&get_op_priority(s.back()) >= get_op_priority(i)){
                    if(s.back() == '(') {
                        s.pop_back();
                        break;
                    }
                    op1 = s.back();
                    s.pop_back();
                    ans += op1;
                }
                s.push_back(i);
            }
        }
        else
        {
            ans += i;
        }
    }
    while (!s.empty()) {
        if(s.back() == '(') {
            s.pop_back();
            break;
        }
        op1 = s.back();
        s.pop_back();
        ans += op1;
    }

    cout << ans << "\n";
}

int get_op_priority(char oper){
    if(oper == '(')
        return 0;
    if(oper == ')')
        return -1;
    if(oper == '+')
        return 1;
    if(oper == '-')
        return 1;
    if(oper == '/')
        return 2;
    if(oper == '*')
        return 2;
}
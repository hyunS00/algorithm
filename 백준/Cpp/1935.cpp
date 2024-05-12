#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N;
double num1, num2;
string expression;
stack<double> s;
vector<double> num(26);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> expression;

    for (int i : expression){
        if(65 <= i && i <=91){
            int alpha = i-65;
            
            if(num[alpha] <= 0)
                cin >> num[alpha];
            s.push(num[alpha]);
        }
        else{
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();

            if((char)i == '*')
                num1 *= num2;
            else if((char)i == '/')
                num1 /= num2;
            else if((char)i == '+')
                num1 += num2;
            else if((char)i == '-')
                num1 -= num2;
            s.push(num1);
        }
    }
    
    cout.precision(2);
    cout << fixed;
    cout << (double)s.top() << "\n";
}
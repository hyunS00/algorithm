#include<iostream>
#include<stack>
using namespace std;

int ans;
string line;
stack<int> s;
char pre;

int main(){
    cin >> line;
    for(char ch : line){
        if(ch == '('){
            s.push(1);
        }
        else{
            s.pop();
            if(pre == '(')
                ans += s.size();
            else
                ans++;
        }
        pre = ch;
    }

    cout << ans << "\n";
}
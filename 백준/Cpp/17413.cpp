#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<char> s;
string S, ans;
int is_tag;

vector<string> split(string str, string delimeter){
    vector<string> ret;
    long pos = 0;
    string token;
    while ((pos = str.find(delimeter)) != string::npos)
    {
        token = str.substr(0, pos);
        ret.push_back(token);
        str.erase(0, pos + delimeter.length());
    }
    ret.push_back(str);
    return ret;
}

int main(){
    getline(cin, S);
    vector<string> splitStr = split(S," ");

    for(string str : splitStr){
        for(char ch : str){
            if(is_tag){
                ans += ch;
                if(ch == '>')
                    is_tag = 0;
            }
            else if (ch == '<'){
                while (!s.empty())
                {
                    ans += s.top();
                    s.pop();
                }
                ans += '<';
                is_tag = 1;
            }
            else{
                s.push(ch);
            }
        }
        while (!s.empty()){
            ans += s.top();
            s.pop();
        }
        ans += ' ';
    }
    cout << ans << "\n";
}
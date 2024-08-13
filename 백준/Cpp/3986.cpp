#include<iostream>
#include<stack>
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, ans = 0;

    cin >> n;
    cin.ignore();

    while (n--)
    {
        stack<char> s;

        string word;
        getline(cin, word);

        for(auto c : word){
            if(s.empty()){
                s.push(c);
            }
            else if(c == 'A' && s.top() == 'A'){
                s.pop();
            }
            else if(c == 'B' && s.top() == 'B'){
                 s.pop();
            }
            else{
                s.push(c);
            }
        }

        if(s.empty()) ans++;
    }

    cout << ans << endl;
}
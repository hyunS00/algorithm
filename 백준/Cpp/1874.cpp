#include<iostream>
#include<stack>
using namespace std;

string getOperator();

int N;
int seq[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> seq[i];
    }

    cout << getOperator() << "\n";
}

string getOperator(){
    string ans = "";
    stack<int> s;
    int nowCnt = 1;

    for(int i = 0; i < N; i++){
        if(s.empty()){
            s.push(nowCnt);
            nowCnt++;
            ans += "+\n";
        }

        if(s.top() < seq[i]){
            while (s.top() != seq[i])
            {
                s.push(nowCnt);
                nowCnt++;
                ans += "+\n";
            }
        }

        if(s.top() == seq[i]){
            ans += "-\n";
            s.pop();
        }
        else
            return "NO";
    }

    return ans;
}
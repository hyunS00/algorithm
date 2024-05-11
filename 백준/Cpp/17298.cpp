#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N, num;
vector<int> A;
stack<int> s, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    A.resize(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = N-1; i >= 0; i--){
        while (!s.empty() && A[i] >= s.top())
        {
            s.pop();
        }
        if(s.empty())
            ans.push(-1);
        else
            ans.push(s.top());
        s.push(A[i]);
    }

    while (!ans.empty())
    {
        num = ans.top();
        cout << num <<" ";
        ans.pop();
    }
    cout << "\n";
}

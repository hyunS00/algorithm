#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N;
vector<int> nums(1000001);
vector<int> A;
stack<int> s, ans;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    A.resize(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
        nums[A[i]]++;
    }

    for(int i = N-1; i >= 0; i--){
        while (!s.empty() && nums[A[i]] >= nums[s.top()]) {
            s.pop();
        }

        if(s.empty()){
            ans.push(-1);
            s.push(A[i]);
        } else {
            ans.push(s.top());
            s.push(A[i]);
        }
    }

    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << "\n";
}
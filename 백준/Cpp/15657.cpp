#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

void dfs(vector<int> number, vector<int> ans, int N, int M, int k);

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> number;
    vector<int> ans(M);

    for (int i = 0 ; i < N; i++){
        int num;
        cin >> num;
        number.push_back(num);
    }

    sort(number.begin(), number.end());

    dfs(number, ans, N, M, 0);
}

void dfs(vector<int> number, vector<int> ans, int N, int M, int k){
    if (k == M){
        for (int i = 0; i < M; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < N; i++){
        if (k >= 1 && ans[k-1] > number[i])
            continue;
        ans[k] = number[i];
        dfs(number, ans, N, M, k + 1);
    }
}
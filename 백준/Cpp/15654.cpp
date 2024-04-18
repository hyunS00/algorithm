#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

void dfs(vector<int> number, vector<int> visit, vector<int> ans, int N, int M, int k);

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> number;
    vector<int> visit(N);
    vector<int> ans(N);
    fill(visit.begin(), visit.end(), 0);

    for (int i=0; i < N; i++){
        int num;
        cin >> num;
        number.push_back(num);
    }

    sort(number.begin(), number.end());

    dfs(number, visit, ans, N, M, 0);
}

void dfs(vector<int> number, vector<int> visit, vector<int> ans, int N, int M, int k){
    if (k == M){
        for(int i = 0; i < M; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++){
        if (visit[i])
            continue;
            
        visit[i] = 1;
        ans[k] = number[i];
        dfs(number, visit, ans, N, M, k+1);
        visit[i] = 0;
    }
}
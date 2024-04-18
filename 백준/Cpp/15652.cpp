#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

void dfs(int N, int M, vector<int> num, int k);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> num(M);

    dfs(N, M, num, 0);
}

void dfs(int N, int M, vector<int> num, int k){
    if (k == M) {
        for (int i = 0; i < M; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++){
        if(k>0 && num[k-1] > i)
            continue;;
        num[k] = i;
        dfs(N, M, num, k+1);
    }
}
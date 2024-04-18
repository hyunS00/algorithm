#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<int> number, vector<int> visit, int N, int M, int n);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    vector<int> visit(N+1);
    vector<int> number(M);
    fill(visit.begin(),visit.end(),0);

    dfs(number,visit, N, M, 0);
}

void dfs(vector<int> number, vector<int> visit,int N, int M, int k){

    if (k == M){
        for (int i = 0; i < M; i++){
            cout << number[i] << " ";
        }
        cout << "\n";
        return;
    }

    int start = k == 0 ? 1 : number[k-1]+1;

    for (int i = start; i <= N; i++){
        if (visit[i])
            continue;
        number[k] = i;
        visit[i] = 1;
        dfs(number, visit, N, M, k+1);
        visit[i] = 0;
    }
}
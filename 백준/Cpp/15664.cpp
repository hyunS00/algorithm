#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> num;
vector<bool> visited;
vector<int> ans;

void backTracking(int cnt, int start);
void printAns();

int main(){
    cin >> N >> M;

    num.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++){
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    backTracking(0, 0);
}

void backTracking(int cnt, int start){
    if (cnt == M){
        printAns();
        return;
    }

    int last = -1;
    for(int i = start; i < N; i++){
        if(visited[i])
            continue;
        if(last == num[i])
            continue;;
        
        last = num[i];
        visited[i] = true;
        ans.push_back(num[i]);

        backTracking(cnt + 1, i);

        visited[i] = false;
        ans.pop_back();
    }
}

void printAns(){
    for(int i = 0; i < M; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
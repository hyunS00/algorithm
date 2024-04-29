#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> number;
vector<int> ans;
vector<bool> visited;

void backTracking(int cnt);
void printAns();

int main(){
    cin >> N >> M;

    number.resize(N);
    visited.resize(N);

    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    sort(number.begin(), number.end());

    backTracking(0);
}

void backTracking(int cnt){
    if (cnt == M){
        printAns();
        return;
    }
    int last = -1;
    for (int i = 0; i < N; i++){
        if (visited[i] || last == number[i])
            continue;

        visited[i] = true;
        ans.push_back(number[i]);
        last = number[i];

        backTracking(cnt+1);
        ans.pop_back();
        visited[i] = false;
    }
}

void printAns(){
    for(int i = 0; i < M; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
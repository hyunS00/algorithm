#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> num;
vector<int> ans;

void backTracking(int cnt);
void printAns();

int main(){
    cin >> N >> M;

    backTracking(0);
}

void backTracking(int cnt){
    if (cnt == M){
        printAns();
        return;
    }

    for(int i = 1; i<= N; i++){
        ans.push_back(i);
        backTracking(cnt + 1);
        ans.pop_back();
    }
}

void printAns(){
    for (int i = 0; i < M; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
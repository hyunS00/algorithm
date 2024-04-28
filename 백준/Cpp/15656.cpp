#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> num;
vector<int> ans;

void backTracking(int cnt, int start);
void printAns();

int main(){
    cin >> N >> M;
    num.resize(N);
    for (int i = 0; i < N; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    backTracking(0,0);
}

void backTracking(int cnt, int start){
    if( cnt == M){
        printAns();
        return;
    }

    for(int i = start; i < N; i++){
        ans.push_back(num[i]);
        backTracking(cnt + 1, start);
        ans.pop_back();
    }
}

void printAns(){
    for (int i = 0; i < M; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
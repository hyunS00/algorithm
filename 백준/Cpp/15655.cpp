#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> num;
vector<int> ans;

void input();
void backTracking(int cnt, int start);

int main(){
    input();

    backTracking(0, 0);
}

void input(){
    cin >> N >> M;
    num.resize(N, 0);
    for (int i = 0; i< N; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
}

void printAns(){
    for(int i = 0; i < M; i++){
        cout << num[ans[i]] << " ";
    }
    cout << "\n";
}

void backTracking(int cnt, int start){
    if (cnt == M){
        printAns();
        return;
    }

    for(int i = start; i < N; i++){
        ans.push_back(i);
        backTracking(cnt+1, i+1);
        ans.pop_back();
    }
}
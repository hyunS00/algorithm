#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> number;
vector<int> ans;

void backTracking(int cnt);
void printAns();

int main(){
    cin >> N >> M;
    number.resize(N);

    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    sort(number.begin(), number.end());

    backTracking(0);
}

void backTracking(int cnt){
    if(cnt == M){
        printAns();
        return;
    }

    int last = -1;
    for(int i = 0; i < N; i++){
        if(last == number[i])
            continue;
        
        last = number[i];
        ans.push_back(number[i]);
        backTracking(cnt+1);
        ans.pop_back();
    }
}

void printAns(){
    for(int i = 0; i < M; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
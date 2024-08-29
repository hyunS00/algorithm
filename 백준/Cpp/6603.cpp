#include<iostream>
#define endl "\n"
#define MAX 13

using namespace std;

int num[MAX];
int arr[MAX];
int isUsed[MAX];
int k;

void func(int c, int s);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    while (true)
    {
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++)
            cin >> num[i];

        fill(isUsed, isUsed+k, 0);

        func(0,0);
        cout << endl;
    }
    
}

void func(int c, int s){
    if(c >= 6){
        for(int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    int start = s == 0 ? 0: s+1;
    for(int i = start; i < k; i++){
        if(isUsed[i]) continue;
        isUsed[i] = true;
        arr[c] = num[i];
        func(c+1, i);
        isUsed[i] = false;
    }
}
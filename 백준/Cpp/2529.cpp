#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

int k;
int num[10];
int isUsed[10];
char a[10];
vector<string> ans;

void func(int c);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> a[i];

    func(0);
    cout << ans[0] << endl;
    cout << ans[ans.size()-1] << endl;
}

void func(int c){
    if(c >= k+1){
        string s = "";
        for(int i = 0; i < c; i++)
            s += to_string(num[i]);
        ans.push_back(s);
        return;
    }

    if(c == 0){
        for(int i = 9; i >= 0; i--){
            if(isUsed[i]) continue;
            isUsed[i] = true;

            num[c] = i;
            func(c+1);
            isUsed[i]= false;
        }
    }
    else if(a[c-1] == '<'){
        for(int i = 9; i >= num[c-1]+1; i--){
            if(isUsed[i]) continue;
            isUsed[i] = true;

            num[c] = i;
            func(c+1);
            isUsed[i]= false;
        }
    }
    else
    {
        for(int i = num[c-1]-1; i >= 0; i--){
            if(isUsed[i]) continue;
            isUsed[i] = true;

            num[c] = i;
            func(c+1);
            isUsed[i]= false;
        }
    }
}
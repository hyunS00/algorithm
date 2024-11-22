#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n, m, k;
int mn = 51;
string ans;
string b[50];
int isLose[50];
unordered_map<char,int> c2i = {{'S',1}, {'R', 2}, {'P',3}};
char i2c[4] = {' ', 'S', 'R', 'P'};

void func(int round, int survivor, string rsp){
    if(survivor <= 0) return;
    if(survivor <= k){
        if(round < mn){
            mn = round;
            ans = rsp;
        }
        return;
    }

    vector<int> loser;
    for(int me = 1; me <= 3; me++){
        int rest = 0;
        for(int i = 0; i < n; i++){
            if(isLose[i]) continue;
            int you = c2i[b[i][round]];
            if(me != you && (me%3)+1 == you) rest++;
            else {
                isLose[i] = true;
                loser.push_back(i);
            }
        }
        cout << endl;
        func(round+1,rest,rsp+i2c[me]);
        for(int i : loser)
            isLose[i] = false;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> b[i];

    func(0, n, "");

    if(mn == 51){
        cout << -1;
    }
    else{
        cout << mn << endl;
        cout << ans;
    }
}
#include<iostream>
#include<queue>
#define N 0
#define S 1
#define endl "\n"

using namespace std;

int k;
deque<int> cogWheel[4];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i  = 0; i < 4; i++){
        string status;
        cin >> status;
        for(int j = 0; j < 8; j++){
            cogWheel[i].push_back(status[j] - '0');
        }
    }

    cin >> k;

    while (k--)
    {
        int wheel, rot;
        cin >> wheel >> rot;

        bool chain[3];
        for(int i = 0; i < 3; i++){
            if(cogWheel[i][2] != cogWheel[i+1][6])
                chain[i] = true;
            else
                chain[i] = false;
        }

        int curRot = rot;
        if(rot == 1){
            cogWheel[wheel-1].push_front(cogWheel[wheel-1].back());
            cogWheel[wheel-1].pop_back();
            curRot = -1;
        }
        else{
            cogWheel[wheel-1].push_back(cogWheel[wheel-1].front());
            cogWheel[wheel-1].pop_front();
            curRot = 1;
        }

        for(int i = wheel-1; i < 3; i++){
            if(!chain[i]) break;
            if(curRot == 1){
                cogWheel[i+1].push_front(cogWheel[i+1].back());
                cogWheel[i+1].pop_back();
                curRot = -1;
            }
            else{
                cogWheel[i+1].push_back(cogWheel[i+1].front());
                cogWheel[i+1].pop_front();
                curRot = 1;
            }
        }

        curRot = 1;
        if(rot == 1)
            curRot = -1;

        for(int i = wheel -2; i >= 0; i--){
            if(!chain[i]) break;
            if(curRot == 1){
                cogWheel[i].push_front(cogWheel[i].back());
                cogWheel[i].pop_back();
                curRot = -1;
            }
            else{
                cogWheel[i].push_back(cogWheel[i].front());
                cogWheel[i].pop_front();
                curRot = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        if(cogWheel[i][0] == 1)
            ans += 1 << i;
    }
    cout << ans << endl;
}
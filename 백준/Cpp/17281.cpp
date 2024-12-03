#include <iostream>
using namespace std;

int n, ans;
int arr[50][9];
int hitter[9];
bool isUsed[9];

void func(int k){
    if(k == 9){
        int score = 0;
        int idx = 0;
        for(int ening = 0; ening < n; ening++){
            int out = 0;
            int plate = 0;
            while(out < 3){
                int result = arr[ening][hitter[idx++]];
                idx %= 9;
                if(result == 0) out++;
                else{
                    plate += 1;
                    while(result--){
                        plate <<= 1;
                        if(plate >= 16){
                            score++;
                            plate &= 15;
                        }
                    }
                }
            }
        }
        ans = max(ans, score);
        return;
    }

    for(int i = 1; i < 9; i++){
        if(isUsed[i]) continue;
        isUsed[i] = 1;
        hitter[k] = i;
        if(k+1 == 3) func(4);
        else func(k+1);
        isUsed[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 9; j++)
            cin >> arr[i][j];

    isUsed[0] = 1;
    hitter[3] = 0;
    func(0);
    
    cout << ans;
}
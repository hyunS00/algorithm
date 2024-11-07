#include<iostream>
#define endl "\n"
#define MAX 100001

using namespace std;

int board[MAX];
int status[MAX];

const int NOT_VISIT = 0;
const int CYCLE_IN = -1;

void run(int x){
    int cur = x;
    while (true) {
        status[cur] = x;
        cur = board[cur];
        if(status[cur] == x){
            while(status[cur] != CYCLE_IN){
                status[cur] = CYCLE_IN;
                cur = board[cur];
            }
            return;
        }
        else if(status[cur] != NOT_VISIT) return;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fill(status+1, status+n+1, NOT_VISIT);

        for(int i = 1; i <= n ; i++){
            cin >> board[i];
        }

        for(int i = 1; i <= n ; i++){
            if(status[i] == NOT_VISIT) run(i);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(status[i] != CYCLE_IN) ans++;
        }

        cout << ans << endl;
    }
}
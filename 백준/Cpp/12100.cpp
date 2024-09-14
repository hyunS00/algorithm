#include<iostream>

using namespace std;

const int LIMIT = 20;

int n, ans;
int board[LIMIT][LIMIT];

void solve(int k, int originBoard[LIMIT][LIMIT]);
void tilt(int dir, int board[LIMIT][LIMIT]);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin >> board[x][y];
        }
    }

    solve(0, board);
    cout << ans << endl;
}

void tilt(int dir, int newBoard[LIMIT][LIMIT]){
    if(dir == 0){
        for(int x = 0; x < n; x++){
            int nums[LIMIT] = {};
            int idx = 0;
            bool doFind = false;
            int originX = -1;
            int originY = -1;
            for(int y = 0; y < n; y++){
                if(doFind && newBoard[x][y] == newBoard[originX][originY]){
                    newBoard[originX][originY] += newBoard[x][y];
                    newBoard[x][y] = 0;
                    doFind = false;
                    nums[idx-1] = newBoard[originX][originY];
                }
                else if(newBoard[x][y] > 0){
                    originX = x;
                    originY = y;
                    doFind = true;
                    nums[idx++] = newBoard[x][y];
                }
            }
            idx = 0;
            for(int y = 0; y < n; y++){
                if(nums[idx] <= 0) newBoard[x][y] = 0;
                else newBoard[x][y] = nums[idx++];
            }
        }
    }
    else if(dir == 1){
        for(int x = 0; x < n; x++){
            int nums[LIMIT] = {};
            int idx = 0;
            bool doFind = false;
            int originX = -1;
            int originY = -1;
            for(int y = n-1; y >= 0; y--){
                if(doFind && newBoard[x][y] == newBoard[originX][originY]){
                    newBoard[originX][originY] += newBoard[x][y];
                    newBoard[x][y] = 0;
                    doFind = false;
                    nums[idx-1] = newBoard[originX][originY];
                }
                else if(newBoard[x][y] > 0){
                    originX = x;
                    originY = y;
                    doFind = true;
                    nums[idx++] = newBoard[x][y];
                }
            }
            idx = 0;
            for(int y = n - 1; y >= 0; y--){
                if(nums[idx] <= 0) newBoard[x][y] = 0;
                else newBoard[x][y] = nums[idx++];
            }
        }
    }
    else if(dir == 2){
        for(int y = 0; y < n; y++){
            int nums[LIMIT] = {};
            int idx = 0;
            bool doFind = false;
            int originX = -1;
            int originY = -1;
            for(int x = 0; x < n; x++){
                if(doFind && newBoard[x][y] == newBoard[originX][originY]){
                    newBoard[originX][originY] += newBoard[x][y];
                    newBoard[x][y] = 0;
                    doFind = false;
                    nums[idx-1] = newBoard[originX][originY];
                }
                else if(newBoard[x][y] > 0){
                    originX = x;
                    originY = y;
                    doFind = true;
                    nums[idx++] = newBoard[x][y];
                }
            }
            idx = 0;
            for(int x = 0; x < n; x++){
                if(nums[idx] <= 0) newBoard[x][y] = 0;
                else newBoard[x][y] = nums[idx++];
            }
        }
    }
    else{
        for(int y = 0; y < n; y++){
            int nums[LIMIT] = {};
            int idx = 0;
            bool doFind = false;
            int originX = -1;
            int originY = -1;
            for(int x = n-1; x >= 0; x--){
                if(doFind && newBoard[x][y] == newBoard[originX][originY]){
                    newBoard[originX][originY] += newBoard[x][y];
                    newBoard[x][y] = 0;
                    doFind = false;
                    nums[idx-1] = newBoard[originX][originY];
                }
                else if(newBoard[x][y] > 0){
                    originX = x;
                    originY = y;
                    doFind = true;
                    nums[idx++] = newBoard[x][y];
                }
            }
            idx = 0;
            for(int x = n - 1; x >= 0; x--){
                if(nums[idx] <= 0) newBoard[x][y] = 0;
                else newBoard[x][y] = nums[idx++];
            }
        }
    }
}

void solve(int k, int originBoard[LIMIT][LIMIT]){
    if(k >= 5){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(originBoard[x][y] > 0)
                    ans = max(ans, originBoard[x][y]);
            }
        }
        return;
    }

    
    for(int dir = 0; dir < 4; dir++){
        int newBoard[LIMIT][LIMIT];

        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                newBoard[x][y] = originBoard[x][y];
            }
        }
        tilt(dir, newBoard);
        solve(k+1, newBoard);
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int N;
vector<vector<char> > board;

int findLongestSequence();

int main() {
    cin >> N;

    board.resize(N,vector<char>(N));

    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // 행 검사
            if(j+1 < N) {
                swap(board[i][j],board[i][j+1]);
                result = max(result, findLongestSequence());
                swap(board[i][j],board[i][j+1]);
            }

            // 열 검사
            if(i+1 < N) {
                swap(board[i][j],board[i+1][j]);
                result = max(result, findLongestSequence());
                swap(board[i][j],board[i+1][j]);
            }
        }
    }

    cout << result << endl;
}

int findLongestSequence(){
    int maxCount = 1;

    for(int i = 0; i < N; i++){
        int count = 1;
        for(int j = 0; j < N-1; j++){
            if(board[i][j] == board[i][j+1]) count++;
            else{
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        maxCount = max(maxCount, count);
    }

    for(int j = 0; j < N; j++) {
        int count = 1;
        for(int i = 0; i < N-1; i++) {
            if(board[i][j] == board[i+1][j]) count++;
            else {
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        maxCount = max(maxCount, count);
    }


    return maxCount;
}
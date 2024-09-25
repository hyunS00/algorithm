#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map <string, int> M;

int board[50][50];
int give[50];
int recive[50];

int solution(vector<string> friends, vector<string> gifts) {
    n = friends.size();
    
    for(int i = 0; i < n; i++){
        string name = friends[i];
        M.insert({name, i});
    }
    
    for(auto s : gifts){
        int pos = s.find(" ", 0);
        string sender = s.substr(0, pos);
        string reciver = s.substr(pos+1, s.size());
        int si =  (M.find(sender))->second;
        int ri = (M.find(reciver))->second;
        board[si][ri]++;
        give[si]++;
        recive[ri]++;
    }
    
    int ans[50] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(board[i][j] < board[j][i]) continue;
            
            if(board[i][j] > board[j][i]) {
                ans[i]++;
            }
            else if(give[i] - recive[i] > give[j] - recive[j]){
                ans[i]++;
            }
        }
    }
    
    int answer = *max_element(ans, ans+n);
    return answer;
}
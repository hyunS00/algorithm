#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>>resultVec;
    resultVec.push_back({1});
    for(int i=1;i<numRows;i++){
        vector<int>vector;
        vector.push_back(resultVec[i-1][0]);
        for(int j=1;j<i;j++){
            vector.push_back(resultVec[i-1][j-1]+resultVec[i-1][j]);
        }
        vector.push_back(resultVec[i-1][i-1]);
        resultVec.push_back(vector);
    }
    return resultVec;
}

int main(){
    auto vector = generate(5);
    for(auto v : vector){
        for(auto vv: v){
            cout<< vv << " ,";
        }
        cout << "\n";
    }
    return 0;
}
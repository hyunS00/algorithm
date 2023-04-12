#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        //int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>reshape={};
        for(int i=0;i<c;i++){
            reshape[i/r][i%r]=mat[i/n][i%n];
        }
        return reshape;
    }

int main(){
    vector<vector<int>> mat = {{1,2},{3,4}};
    int r =1;
    int c =4;
    vector<vector<int>>reshape={};
    reshape = matrixReshape(mat,r,c);
    for(auto v1:reshape){
        for(auto v2:v1){
            cout << v2 << ", ";
        }
        cout << "\n";
    }
    return 0;
}
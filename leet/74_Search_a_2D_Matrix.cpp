#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int start=0;
    int end = matrix.size()-1;
    int mid;

    while(end-start<2&&start<end&&mid>1){
        mid=(end-start)/2;
        cout<<start<<" , "<<mid<<" , "<<end<<"\n";
        if(target==matrix[mid][0]){
            return true;
        }else if(target<matrix[mid][0]){
            end=mid-1;
        }else if(target>matrix[mid][0]){
            start = mid+1;
        }
    }
    cout<<start<<" , "<<mid<<" , "<<end<<"\n";
    for(auto v:matrix[start]){
        if(target==v)
            return true;
    }
    for(auto v:matrix[mid]){
        if(target==v)
            return true;
    }
    for(auto v:matrix[end]){
        if(target==v)
            return true;
    }
    return false;
}

int main(){
    vector<vector<int>>matrix = {{1},{3},{5}};
    int target =3;
    bool result = searchMatrix(matrix,target);
    cout << result << "\n";
}
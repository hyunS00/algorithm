#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int point1=0;
        int point2=0;
        vector<int>merge;
        while(!(point1>=m || point2>=n)){
            if(nums1[point1]<=nums2[point2]){
                merge.push_back(nums1[point1++]);
            }else{
                merge.push_back(nums2[point2++]);
            }
        }
        for(;point1<m;point1++){
            merge.push_back(nums1[point1]);
        }
        for(;point2<n;point2++){
            merge.push_back(nums2[point2]);
        }
        nums1=merge;
    }
};
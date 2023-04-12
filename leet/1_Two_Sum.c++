#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0;i<nums.size()-1;i++){
        auto index = find(nums.begin()+i,nums.end(),9-nums[i]);
        if(index!=nums.end()){
            return vector<int>(i,index-nums.begin());
        }
        
        }
        return vector<int>();   
    }
};
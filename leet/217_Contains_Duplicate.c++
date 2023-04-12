#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(num==nums[i])
                return true;
            num=nums[i];
        }
        return false;
    };

};
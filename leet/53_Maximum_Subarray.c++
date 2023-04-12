#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start=0;
        int end=0;
        int largestSum=-100001;
        int intervalSum=0;
        while(start>=nums.size()&&end>=nums.size()){
            if(intervalSum>largestSum){
                largestSum=intervalSum;
                intervalSum+=nums[end];
                end++;
            }else{
                intervalSum -=nums[start];
                start++;
            }
        }
        return largestSum;
    }
};
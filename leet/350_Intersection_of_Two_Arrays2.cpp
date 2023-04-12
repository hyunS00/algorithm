#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    int hashArr1[1001]={};
    int hashArr2[1001]={};

    for(int i=0;i<nums1.size();i++)
        hashArr1[nums1[i]]++;
    for(int i=0;i<nums1.size();i++)
        cout<< hashArr1[i] << ",";
    cout<< " hashArr1\n";

    for(int i=0;i<nums2.size();i++)
        hashArr2[nums2[i]]++;
    for(int i=0;i<nums2.size();i++)
        cout<< hashArr2[i] << ",";
    cout<< " hashArr2\n";

    for(int i=0; i<1001;i++){
        while(hashArr1[i]>0&&hashArr2[i]>0){
            result.push_back(i);
            hashArr1[i]--;
            hashArr2[i]--;
        }
    }
    return result;
}

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result = intersect(nums1,nums2);
    for(auto v:result)
        cout<< v<<'\n';
    return 0;
}
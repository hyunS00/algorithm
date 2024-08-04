#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int avg,middle;
int nums[5];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int sum = 0;
    for(int i = 0; i < 5; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    avg = sum / 5;

    sort(nums, nums+5);
    middle = nums[2];

    cout << avg << endl << middle << endl;
}
#include<iostream>
#define endl "\n"

using namespace std;

int nums[3];
int answer[3];
int main(){
    for(int i = 0; i < 3; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < 3; i++){
        int idx = 0;
        for(int j = 0; j < 3; j++){
            if(i == j) continue;

            if(nums[i] > nums[j])
                idx++;
        }
        answer[idx] = nums[i];
    }

    for(int i = 0; i < 3; i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}
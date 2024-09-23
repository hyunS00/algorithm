#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int n;
vector<int> negative;
vector<int> positive;
vector<int> zero;
vector<int> one;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(num < 0)
            negative.push_back(num);
        else if(num == 0)
            zero.push_back(0);
        else if(num == 1)
            one.push_back(1);
        else
            positive.push_back(num);
    }

    sort(negative.begin(), negative.end(), greater<int>());
    sort(positive.begin(), positive.end());

    int ans = 0;
    while (negative.size() >= 2) {
        int num1 = negative.back(); negative.pop_back();
        int num2 = negative.back(); negative.pop_back();
        ans += num1 * num2;
    }

    while (!zero.empty() && !negative.empty()) {
        negative.pop_back();
        zero.pop_back();
    }


    while (!negative.empty()) {
        int num = negative.back(); negative.pop_back();
        ans += num;
    }
    
    while (!one.empty()) {
        int num = one.back(); one.pop_back();
        ans += num;
    }
    
    while (positive.size() >= 2)
    {
        int num1 = positive.back(); positive.pop_back();
        int num2 = positive.back(); positive.pop_back();
        ans += num1 * num2;
    }

    if(!positive.empty()){
        int num = positive.back(); positive.pop_back();
        ans += num;
    }

    cout << ans << endl;
}
#include<iostream>
#include<algorithm>
using namespace std;

const int LIMIT = 500000;

int n, m;
int card[LIMIT];

int upper_idx(int st, int en, int target){
    while (st < en) {
        int mid = (st + en) / 2;
        if(card[mid] > target) en = mid;
        else st = mid +1;
    }
    return st;
}

int lower_idx(int st, int en, int target){
    while (st < en) {
        int mid = (st + en) / 2;
        if(card[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> card[i];

    sort(card, card + n);

    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << upper_idx(0, n, num) - lower_idx(0, n, num) << " ";
    }
}
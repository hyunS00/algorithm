#include<iostream>
#include<algorithm>
#define endl "\n"
#define MAX 500000

using namespace std;

int n,m;
int card[MAX];

bool binary_search(int target, int start, int end);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> card[i];
    }

    sort(card, card + n);

    cin >> m;

    while(m--){
        int num;
        cin >> num;

        cout << binary_search(num, 0, n-1) << " ";
    }

    cout << endl;
}

bool binary_search(int target, int start, int end){
    int mid = (start + end) / 2;
    
    if(start < 0 || end >= n || start > end)
        return false;

    if(card[mid] == target)
        return true;
    
    if(card[mid] > target)
        return binary_search(target, start, mid-1);
    else
        return binary_search(target, mid+1, end);
}
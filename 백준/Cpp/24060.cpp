#include<iostream>
#define endl "\n"

using namespace std;

const int MAX_N = 500000;

int a[MAX_N];
int tmp[MAX_N];
int n, k, cnt;

void check(int idx){
    if(++cnt >= k){
        cout << tmp[idx] << endl;
        exit(0);
    }
}

void merge_arr(int left, int right, int mid){
    int i = left, j = mid+1, t = 0;
    while (i <= mid && j <= right)
    {
        if(a[i] <= a[j]){
            tmp[t++] = a[i++];
        }
        else{
            tmp[t++] = a[j++];
        }
        check(t-1);
    }
    
    while (i <= mid){
        tmp[t++] = a[i++];
        check(t-1);
    }
    
    while (j <= right){
        tmp[t++] = a[j++];
        check(t-1);
    }

    i = left;
    t = 0;
    while (i <= right)
    {
        a[i++] = tmp[t++];
    }
        
}

void merge_sort(int left, int right){
    if(left < right){
        int mid = (left + right) /2;
        merge_sort(left, mid);
        merge_sort(mid+1,right);
        merge_arr(left, right, mid);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(0, n-1);

    cout << -1 << endl;
}
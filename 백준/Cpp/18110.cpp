#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int n;
int arr[300001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);

    int slice = round((double)n * 0.15);
    double sum = 0;
    for(int i = slice; i < n - slice; i++)
        sum += arr[i];
    cout << (int)round(sum / (n-(2*slice))) << endl;
}
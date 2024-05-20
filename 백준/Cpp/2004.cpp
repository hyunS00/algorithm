#include<iostream>
using namespace std;

int n, m;
int calculate5(int num);
int calculate2(int num);

int main(){
    int cnt_2, cnt_5;

    cin >> n >> m;

    cnt_2 = calculate2(n) - calculate2(m) - calculate2(n-m);
    cnt_5 = calculate5(n) - calculate5(m) - calculate5(n-m);

    cout << min(cnt_2, cnt_5) << "\n";
}

int calculate5(int num) {
    int cnt = 0;
    while (num > 0)
    {
        cnt += num / 5;
        num /= 5;
    }
    
    return cnt;
}

int calculate2(int num) {
    int cnt = 0;

    while (num > 0)
    {
        cnt += num / 2;
        num /= 2;
    }

    return cnt;
}
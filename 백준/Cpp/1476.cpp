#include<iostream>
#define MAX_E 15
#define MAX_S 28
#define MAX_M 19
#define endl "\n"
using namespace std;

int E, S, M;
int getYear();

int main() {
    cin >> E >> S >> M;
    int ans = getYear();
    cout << ans << endl;
}

int getYear() {
    int e = 1;
    int s = 1;
    int m = 1;

    int year = 1;
    while (!(e == E && s == S && m == M)) {
        if(++e > MAX_E) e = 1;
        if(++s > MAX_S) s = 1;
        if(++m > MAX_M) m = 1;
        year++;
    }

    return year;
}
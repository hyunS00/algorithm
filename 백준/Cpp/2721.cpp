#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;
typedef long long ll;

int triangular_number(int n) {
    return n * (n + 1) / 2;
}

ll weighted_sum(int n) {
    ll sum = 0;
    for (int k = 1; k <= n; ++k) {
        sum += k * triangular_number(k + 1);
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    vector<int> test_cases(T);
    
    for (int i = 0; i < T; ++i)
        cin >> test_cases[i];
    
    for (int i = 0; i < T; ++i)
        cout << weighted_sum(test_cases[i]) << endl;
    
    return 0;
}
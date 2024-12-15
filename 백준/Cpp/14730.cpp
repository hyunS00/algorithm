#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b > 0) {
            result += a * b;
        }
    }

    cout << result;
}
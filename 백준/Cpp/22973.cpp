#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long K;
    cin >> K;

    K = abs(K);  // 음수 처리 (양수로 변환)

    // K가 0이면 점프할 필요 없음
    if (K == 0) {
        cout << 0 << endl;
    }
    // K가 짝수일 경우 도달 불가능
    else if (K % 2 == 0) {
        cout << -1 << endl;
    }
    // K가 홀수일 경우, 비트 길이로 최소 점프 계산
    else {
        cout << (int)log2(K) + 1 << endl;
    }

    return 0;
}

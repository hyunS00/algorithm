#include<iostream>
#define MAXLEN 100000
#define endl "\n";

using namespace std;

int N, M, A, x;
int moNum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, A;
    cin >> N >> M >> A;

    int called;
    while (true) {
        cin >> called;

        // 입력의 끝을 만나면 종료
        if (called == M/2+1) {
            cout << 0 << endl;
            break;
        }

        // 호출된 모 번호에 해당하는 참가자 번호 계산
        int num = (called - (M/2+1) + A - 1 + N) % N + 1;
        cout << num << endl;
        A = num; // 새로운 주최자 설정
    }

    return 0;
}
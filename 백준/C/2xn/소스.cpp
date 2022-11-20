#include<iostream>
using namespace std;
int main() {
	int arr[1001] = { 0, 1, 2, 3, };
	int n;
	cin >> n;
	for (int i = 4; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	cout << arr[n] % 10007;
	return 0;
}
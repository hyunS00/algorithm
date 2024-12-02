#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    if(a.size() < b.size()) swap(a, b);

    int as = a.size();
    int bs = b.size();
    string ans = "";

    int carry = 0;
    for(int i = 0; i < as; i++){
        int digitA = a[as - 1 - i] - '0';
        int digitB = (i < bs) ? (b[bs - 1 - i] - '0') : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans += (digit + '0');
    }

    if(carry) ans += (carry + '0');

    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}

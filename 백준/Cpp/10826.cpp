#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;

string dp[10001];

string add(string a, string b){
    if(b.size() < a.size())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res = "0";
    for(int i = 0; i < b.size(); i++){
        int n1 = i < a.size() ? a[i]-'0' : 0;
        int n2 = b[i]-'0';
        int digit = n1+n2+(res[i]-'0');
        int carry = digit/10;
        digit %= 10;
        res[i] = digit+'0';
        res += carry+'0';
    }
    if(res[res.size()-1]=='0')
        res = res.substr(0, res.size()-1);

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    dp[0] = "0";
    dp[1] = "1";

    for(int i = 2; i <= n; i++)
        dp[i] = add(dp[i-1], dp[i-2]);

    cout << dp[n] << endl;
}
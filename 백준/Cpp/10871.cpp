#include <iostream>
#define endl "\n"

using namespace std;


int N, X;
string answer;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> X;
    while (N--)
    {
        int a;
        cin >> a; 
        if(a < X)
            answer = answer + to_string(a) + " ";
    }
    
    cout << answer << endl;
}
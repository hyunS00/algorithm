#include<iostream>
#include<queue>
using namespace std;

int N, K;
string ans = "<";
int main(){
    cin >> N >> K;
    
    queue<int> person;
    for(int i = 1; i <= N; i++){
        person.push(i);
    }

    while (person.size() > 1)
    {
        for(int i = 0; i < K - 1; i++){
            person.push(person.front());
            person.pop();
        }
        ans += to_string(person.front()) + ", ";
        person.pop();
    }
    
    ans += to_string(person.front()) + ">";
    cout << ans << "\n";
}

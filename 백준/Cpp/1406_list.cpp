#include<iostream>
#include <list>
#define endl "\n"

using namespace std;

string line;
int N;
list<char> L;
list<char>::iterator cursor = L.begin();

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> line >> N;

    for(char c: line) L.push_back(c);
    cursor = L.end();

    while (N--)
    {
        char command;
        cin >> command;

        if(command == 'L') {
            if(cursor != L.begin()) cursor--;
        }
        else if(command == 'D'){
            if(cursor != L.end()) cursor++;
        }
        else if(command == 'B'){
            if(cursor != L.begin()) cursor = L.erase(--cursor);
        }
        else {
            char character;
            cin >> character;
            L.insert(cursor, character);
        }
    }

    for(auto c : L) cout << c;
    cout << endl;
}
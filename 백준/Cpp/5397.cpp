#include<iostream>
#include<list>
#define endl "\n"

using namespace std;

int t;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while (t--)
    {
        string line;
        list<char> L;
        list<char>::iterator cursor = L.begin();

        cin >> line;
        for(auto c : line){
            if(c == '<'){
                if(cursor != L.begin()) cursor--;
            }
            else if(c == '>'){
                if(cursor != L.end()) cursor++;
            }
            else if(c == '-'){
                if(cursor != L.begin()) cursor = L.erase(--cursor);
            }
            else{
                L.insert(cursor, c);
            }
        }

        for(auto c : L) cout << c;
        cout << endl;
    }
    
}
#include<iostream>
#include<vector>
using namespace std;

string line;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, line);

    cin >> N;
    vector<char> left;
    vector<char> right;
    for(int i = 0; i< line.size(); i++){
        left.push_back(line[i]);
    }

    while (N--)
    {
        char op;
        cin >> op;
        if(op == 'P'){
            char val;
            cin >> val;
            left.push_back(val);
        }
        else if(op == 'L'){
            if(!left.empty()){
                right.push_back(left.back());
                left.pop_back();
            }
        }
        else if(op == 'D'){
            if(!right.empty()){
                left.push_back(right.back());
                right.pop_back();
            }
        }
        else if(op == 'B'){
            if(!left.empty()){
                left.pop_back();
            }
        }
    }
    while (!right.empty())
    {
        left.push_back(right.back());
        right.pop_back();
    }

    for(int i = 0; i < left.size(); i++){
        cout << left[i];
    }
    cout << "\n";
}
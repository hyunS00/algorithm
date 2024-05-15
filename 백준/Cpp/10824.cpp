#include<iostream>
#include<vector>
using namespace std;

long num1, num2;
string line;
vector <string> split_num;

vector<string> split(string line, string token);

int main(){
    getline(cin, line);
    split_num = split(line, " ");

    num1 = stol(split_num[0] + split_num[1]);
    num2 = stol(split_num[2] + split_num[3]);
    cout << num1 + num2 << "\n";
}

vector<string> split(string line, string delimiter){
    vector<string> ret;
    int pos = 0;
    string token = "";
    while ((pos = line.find(delimiter)) != string::npos)
    {
        token = line.substr(0, pos);
        ret.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    ret.push_back(line);
    return ret;
}
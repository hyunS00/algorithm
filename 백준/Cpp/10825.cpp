#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<tuple<int, int, int, string>> students;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string name;
        int ko, en, ma;
        cin >> name >> ko >> en >> ma;
        students.push_back({-ko, en, -ma, name});
    }

    sort(students.begin(), students.end());

    for(int i = 0; i < n; i++)
        cout << get<3>(students[i]) << "\n";
}
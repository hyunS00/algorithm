#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int, int> > position;
int cmp(pair<int, int> n, pair<int, int> m);

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        position.push_back(pair<int, int>(x, y));
    }
    
    sort(position.begin(), position.end(), cmp);

    for (int i = 0; i < N; i++){
        cout << position[i].first << " " << position[i].second << "\n";
    }
}

int cmp(pair<int, int> n, pair<int, int> m){
    if(n.second == m.second)
        return n.first < m.first;
    return n.second < m.second;
}
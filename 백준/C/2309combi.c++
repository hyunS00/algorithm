#include <bits/stdc++.h>
using namespace std;

vector <int> dwarf(9);
int tall_sum=0;

void combi(int index,vector<int> v){
    if(v.size()==2){
        if(tall_sum - dwarf[v[0]] - dwarf[v[1]] == 100){
            for(auto i: dwarf){
                if(dwarf[v[0]]==i||dwarf[v[1]]==i) continue;
                cout << i << endl;
            }
            exit(0);
        }
        return;
    }

    for(int i=index+1;i<9;i++){
        v.push_back(i);
        combi(i+1,v);
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    for(int i=0;i<9;i++){
        cin >> dwarf[i];
        tall_sum += dwarf[i];
    }
    sort(dwarf.begin(),dwarf.end());

    combi(-1,v);
    
    return 0;
} 
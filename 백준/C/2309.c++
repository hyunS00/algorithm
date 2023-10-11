#include <bits/stdc++.h>
using namespace std;

vector <int> dwarf(9);
int tall_sum=0;

int main(){
    for(int i=0;i<=8;i++){
        cin >> dwarf[i];
        tall_sum += dwarf[i];
    }

    sort(dwarf.begin(),dwarf.end());

    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if(tall_sum - dwarf[i]-dwarf[j]==100){
                dwarf.erase(dwarf.begin()+j);
                dwarf.erase(dwarf.begin()+i);
                    for(auto it : dwarf){
                        cout<< it << endl;
                    }
                return 0;
            }
        }
    }
}
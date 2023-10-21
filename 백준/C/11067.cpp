#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, n, x, y, m, cafeNum;
    vector<vector<int>> cafePoses(1000000);
    vector<pair<int,int>> cafeIndex;
    int maX = -1;
    cin >> T;
    for(int i=0;i<T;i++){
        cafePoses.reserve(1000000);
        cafeIndex.clear();
        maX = -1;

        cin >> n;
        for(int i=0; i< n; i++){
            cin >> x >> y;
            maX = max(x,maX);
            cafePoses[x].push_back(y);
        }

        for(int x = 0; x<maX+1;x++){
            sort(cafePoses[x].begin(),cafePoses[x].end());
        }

        int baseY = 0;
        for(int i=0;i<maX+1;i++){
            if(cafePoses[i].empty()) continue;
            pair<int,int> pos;
            if(abs(cafePoses[i][0]-baseY)<=abs(cafePoses[i][cafePoses[i].size()-1]-baseY)){
                for(int j=0;j<cafePoses[i].size();j++){
                    pos.first = i;
                    pos.second = cafePoses[i][j];
                    cafeIndex.push_back(pos);
                }
            }else{
                for(int j=cafePoses[i].size()-1; j > -1; j--){
                    pos.first = i;
                    pos.second = cafePoses[i][j];
                    cafeIndex.push_back(pos);
                }
            }
            baseY = cafeIndex.back().second;
        }

        cin >> m ;
        for(int j=0; j<m;j++){
            cin >> cafeNum;
            cout << cafeIndex[cafeNum-1].first << " " << cafeIndex[cafeNum-1].second << endl;
        }
    }
}
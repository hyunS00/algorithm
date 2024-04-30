#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, minDist = 100000000;
vector<pair<int, int> > chiken;
vector<pair<int, int> > house;
vector<vector<int> > dist;
vector<int> selectChiken;

void backTracking(int cnt, int start);
int calculateDist();

int main(){
    cin >> N >> M;

    int num;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num;
            if(num == 1)
                house.push_back(pair<int, int>(i,j));
            else if (num == 2)
                chiken.push_back(pair<int, int>(i, j));
        }
    }

    dist.resize(house.size(), vector<int>(chiken.size()));

    for(int i = 0; i < house.size(); i++){
            int houseX = house[i].first;
            int houseY = house[i].second;
        for (int j = 0; j < chiken.size(); j++){
            int chikenX = chiken[j].first;
            int chikenY = chiken[j].second;

            dist[i][j] = abs(houseY-chikenY) + abs(houseX - chikenX);
        }
    }

    backTracking(0, 0);
    cout << minDist << "\n";
}

void backTracking(int cnt, int start){
    if(cnt == M){
        minDist = min(minDist, calculateDist());
        return;
    }

    for(int i = start; i < chiken.size(); i++){

        selectChiken.push_back(i);

        backTracking(cnt + 1,i+1);

        selectChiken.pop_back();
    }
}

int calculateDist(){
    int sum = 0;
    for(int i = 0; i < house.size(); i++){
        int minHomeToChiken = 100000000;
        for(int j = 0; j < M; j++){
            minHomeToChiken = min(minHomeToChiken,dist[i][selectChiken[j]]);
        }
        sum += minHomeToChiken;
    }

    return sum;
}
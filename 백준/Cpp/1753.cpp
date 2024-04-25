#include<vector>
#include<iostream>
#include<queue>
#define INF 987654321
using namespace std;

vector<int> finish(20001);
vector<vector<pair<int, int> > > graph(20001);
vector<int> cost(20001);
struct cmp{
    bool operator()(pair<int,int>&a, pair<int, int>&b){
        return a.first > b.first;
    }
};


void dijkstra(int k);

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    fill(cost.begin(),cost.end(),INF);
    int V, E, K;
    cin >> V >> E >> K;

    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(pair<int, int>(w, v));
    }
    
    dijkstra(K);

    for (int i = 1; i <= V; i++){
        if (cost[i] >= INF)
            cout << "INF\n";
        else
            cout << cost[i] << "\n";
    }
}

void dijkstra(int k){
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    q.push(pair<int, int>(0,k));
    cost[k] = 0;

    while (!q.empty())
    {
        pair<int, int> curPair = q.top();
        int curCost = curPair.first;
        int curNode = curPair.second;
        q.pop();
        finish[curNode] = 1;

        for (int i = 0; i < graph[curNode].size(); i++){
            int w = graph[curNode][i].first;
            int v = graph[curNode][i].second;
            if (finish[v])
                continue;

            if (curCost + w < cost[v]){
                cost[v] = curCost + w;
                q.push(pair<int, int>(cost[v] , v));
            }
        }
    }
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

int indegree[1000001];
int outdegree[1000001];
vector<int> G[1000001];
bool visited[1000001];

vector<int> solution(vector<vector<int>> edges) {
    for(auto v : edges){
        int from = v[0];
        int to = v[1];
        indegree[to]++;
        outdegree[from]++;
        
        G[from].push_back(to);
        G[to].push_back(from);
    }
    
    int mn = 1000000;
    int mn_idx = -1;
    for(int i = 0; i <= 1000000; i++){
        if(G[i].empty()) continue;
        
        if(indegree[i] - outdegree[i] < mn){
            mn = indegree[i] - outdegree[i];
            mn_idx = i;
        }
    }
    
    vector<int> answer;
    answer.push_back(mn_idx);
    int donut = 0;
    int stick = 0;
    int eight = 0;
    for(auto start : G[mn_idx]){
        queue<int> Q;
        Q.push(start);
        visited[start] = true;
        int edge = 0;
        int vertex = 1;
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(auto next : G[cur]){
                if(next == mn_idx) continue;
                edge++;
                if(visited[next]) continue;
                Q.push(next);
                visited[next] = true;
                vertex++;
            }
        }
        if(vertex == edge/2)
            donut++;
        else if(edge/2 == vertex-1)
            stick++;
        else
            eight++;
    }
    
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    return answer;
}
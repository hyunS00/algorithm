#include<iostream>
#include<vector>
#define MAX 100000001
using namespace std;

void floyd_warshall();
void printAns();
vector<vector<int> > graph;
int n, m;

int main(){
    cin >> n >> m;

    graph.resize(n+1,vector<int>(n+1, MAX));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < graph[a][b])
            graph[a][b] = c;
    }
    for(int i = 0; i <= n; i++){
        graph[i][i] = 0;
    }

    floyd_warshall();
    printAns();
}

void floyd_warshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void printAns(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (graph[i][j] >= MAX)
                graph[i][j] = 0;
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}
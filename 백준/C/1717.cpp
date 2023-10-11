#include <bits/stdc++.h>
using namespace std;

int getParent(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x] = getParent(parent,parent[x]);
}

void unionParent(int parent[], int a, int b){
    a = getParent(parent,a);
    b = getParent(parent,b);

    if(a>b) parent[a]= b; 
    else parent[b] = a;
}

string findUnion(int parent[],int a, int b){
    a = getParent(parent,a);
    b = getParent(parent,b);

    if(a==b) return "YES\n";
    return "NO\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m=0;
    cin >> n >> m;

    int parent[n+1];

    for(int i=0; i<n+1;i++){
        parent[i]=i;
    }
    while(m>0){
        m--;

        int oper,a,b;
        cin >> oper >> a >> b;

        if (oper) {
            cout << findUnion(parent,a,b);
        } else {
            unionParent(parent,a,b);
        }
    }
    for(auto i : parent){
        cout << i <<endl;
    }
}
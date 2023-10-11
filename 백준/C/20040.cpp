#include <bits/stdc++.h>
using namespace std;

int getParent(int point[], int a){
    if(point[a]==a) return a;
    return point[a]= getParent(point,point[a]);
}

bool findCycle(int point[],int a, int b){
    return point[a]==point[b];
}

bool unionPoint(int point[], int a, int b){
    a = getParent(point,a);
    b = getParent(point,b);
    if(findCycle(point,a,b)) return 1;

    if(a>b) point[a]= b; 
    else point[b] = a;

    return 0;
}

int main(){
    int n,m;
    
    cin >> n >> m;
    int point[n];
    for(int i=0;i<n;i++){
        point[i]=i;
    }

    int count = 0;
    int isCycle = 0;

    while(!isCycle&&count < m){
        ++count;
        int a,b;
        cin >> a >> b;

        isCycle = unionPoint(point,a,b);
    }

    if(!isCycle){
        count = 0;
    }
    cout << count << endl;
}
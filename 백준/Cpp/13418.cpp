#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

int n, m;
tuple<int, int, int> edge[500000];
int bp[1005];
int wp[1005];

int find (int x, int p[]){
    if(p[x] == 0) return x;
    return p[x] = find(p[x], p);
}

bool is_diff_group(int a, int b, int p[]){
    a = find(a, p);
    b = find(b, p);

    if(a == b) return 0;
    else if(a < b) p[b] = a;
    else p[a] = b;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    sort(edge+1, edge+m+1);

    int worst = 0;
    int best = 0;
    int a, b, c;
    tie(c, a, b) = edge[0];
    if(is_diff_group(a, b, wp) && c == 0) worst++;
    if(is_diff_group(a, b, bp) && c == 0) best++;

    for(int i = 1; i <= m; i++){
        int wa, wb, wc; // worst인 경우
        int ba, bb, bc; // best인 경우
        tie(wc, wa, wb) = edge[i];
        tie(bc, ba, bb) = edge[m-i+1];

        if(is_diff_group(wa, wb, wp) && wc == 0) worst++;
        if(is_diff_group(ba, bb, bp) && bc == 0) best++;
    }

    cout << abs(worst*worst - best*best);
}
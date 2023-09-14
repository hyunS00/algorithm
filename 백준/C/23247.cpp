#include <bits/stdc++.h>
using namespace std;

void Solve(vector<vector<int>> map,int n,int m,int* cnt);
void Prefix_Sum(vector<vector<int>> &map,int n,int m);
void displayMap(vector<vector<int>> map){
    cout<< "--------display-----------" << "\n";
    for (auto it = map.begin(); it != map.end(); it++) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
			cout << *it2 << " ";
		}
        cout << "\n";
	}
    cout << "\n";
}

int main(){
    int n,m;

    cin >> n >> m;
    vector<vector<int>> map(n+1);
    vector<int> v(m+1,0);
    map[0]=v;
    for (auto it = map.begin()+1; it != map.end(); it++) {
		(*it).resize(m+1, 0);
        //(*it) = vector<int>(N);
		for (auto it2 = (*it).begin()+1; it2 != (*it).end(); it2++) {
			cin >> (*it2);
		}
	}

    Prefix_Sum(map,n,m);

    displayMap(map);

    int cnt = 0;

    Solve(map,n,m,&cnt);

    cout << cnt << "\n";
}

void Solve(vector<vector<int>> map,int n,int m,int* cnt){

    for(int rb_y=1; rb_y<=n;rb_y++){
        for(int rb_x=1;rb_x<=m;rb_x++){
            for(int lt_y = rb_y; lt_y>0 ; lt_y--){
                for(int lt_x = rb_x;  lt_x>0 ;  lt_x--){
                    if(map[rb_y][rb_x]-map[rb_y][lt_x-1]-map[lt_y-1][rb_x]+map[lt_y-1][lt_x-1]==10) (*cnt)++;
                    else if(map[rb_y][rb_x]-map[rb_y][lt_x-1]-map[lt_y-1][rb_x]+map[lt_y-1][lt_x-1]>10)break;  
                }
                
            }
        }
    }

    // for(int lt_y = 1; lt_y<=n ; lt_y++){
    //     for(int lt_x = 1;  lt_x<=m ;  lt_x++){
    //             for(int rb_y=lt_y; rb_y<=n;rb_y++){
    //                 for(int rb_x=lt_x;rb_x<=m;rb_x++){
    //                     if(map[rb_y][rb_x]-map[rb_y][lt_x-1]-map[lt_y-1][rb_x]+map[lt_y-1][lt_x-1]==10) (*cnt)++;
    //                     else if(map[rb_y][rb_x]-map[rb_y][lt_x-1]-map[lt_y-1][rb_x]+map[lt_y-1][lt_x-1]>10)break;
    //             }
    //         }
    //     }
    // }
}

void Prefix_Sum(vector<vector<int>>& map,int n, int m){
    for(int i=1; i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j] = map[i][j] + map[i][j-1];
        }
    }
    for(int i=1; i<=m;i++){
        for(int j=1;j<=n;j++){
            map[j][i] = map[j][i] + map[j-1][i];
        }
    }
}
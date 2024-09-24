#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int n, k;
int plug[101];
int active[101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for(int i = 1; i <= k; i++)
        cin >> plug[i];

    int cnt = 0;
    int ans = 0;
    for(int i = 1; i <= k; i++){
        int num = plug[i];

        if(active[num]) continue;

        if(cnt < n){
            active[num] = true;
            cnt++;
        }
        else{
            vector<pair<int, int> > t;
            for(int j = 1; j <= k; j++) {
                if(!active[j]) continue;

                int next_use = k + 1;
                for(int l = i + 1; l <= k; l++) {
                    if(plug[l] == j) {
                        next_use = l;
                        break;
                    }
                }
                t.push_back({next_use, j});
            }
            sort(t.begin(), t.end(), greater<pair<int, int>>());
            int to_remove = t[0].second;
            active[to_remove] = false;
            active[num] = true;
            ans++;
        }
    }

    cout << ans << endl;
}
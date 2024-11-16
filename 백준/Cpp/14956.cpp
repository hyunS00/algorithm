#include<iostream>
#define X first
#define Y second
using namespace std;

int n, m;
pair<int,int> func(int k, int walk){
    if(k == 2){
        switch(walk){
            case 1:
                return {1, 1};
            case 2:
                return {1, 2};
            case 3:
                return {2, 2};
            case 4:
                return {2, 1};
        }
    }

    int mid = k/2;
    int section = mid*mid;
    if(walk <= section){
        pair<int, int> pil = func(mid, walk);
        return {pil.Y, pil.X};
    }
    else if(walk <= 2*section){
        pair<int, int> pil = func(mid, walk-section);
        return {pil.X, mid+pil.Y};
    }
    else if(walk <= 3*section){
        pair<int, int> pil = func(mid, walk-section*2);
        return {mid+pil.X, mid+pil.Y};
    }
    else {
        pair<int, int> pil = func(mid, walk-section*3);
        return {2*mid-pil.Y+1, mid-pil.X+1};
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    pair<int,int> ans = func(n, m);
    cout << ans.X << " " << ans.Y;
}
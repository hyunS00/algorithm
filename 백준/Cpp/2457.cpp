#include<iostream>
#include<algorithm>
using namespace std;

int n;
const int month[13] = {0, 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31};
pair<int, int> date[100000];

bool cmp(pair<int, int>a, pair<int, int> b);
int getDate(int m, int d);

int start = getDate(3, 1);
int finish = getDate(11, 30);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int sm, sd, em, ed;
        cin >> sm >> sd >>em >> ed;
        int s = getDate(sm, sd);
        int e = getDate(em, ed) -1;
        if(s < start) s = start;
        if(e > finish) e = finish;

        date[i] = {s, e};
    }

    sort(date, date+n, cmp);

    int cnt = 0;
    int base = start -1;

    for(int i = 0; i < n; i++){
        int s = date[i].first;
        int e = date[i].second;

        if(base >= e || s > base +1) continue;
        int mxi = i;
        for(int j = i +1; j < n && date[j].first <= base+1; j++){
            if(date[j].second >= date[mxi].second)
                mxi = j;
        }
        cnt++;
        base = date[mxi].second;
        i = mxi;
    }
    if(base < finish)
        cnt = 0;

    cout << cnt << endl;
}

bool cmp(pair<int, int>a, pair<int, int> b){
    
    return a.first < b.first;
}

int getDate(int m, int d){
    int sum = 0;
    for(int i = 1; i <= m; i++)
        sum += month[i];
    sum += d;
    return sum;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define endl "\n"

using namespace std;

int n;
vector<int> v1;
int cnt[8001];
bool cmp(int a, int b){
    if(cnt[a] == cnt[b]) return a < b;
    return cnt[a] > cnt[b];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v1.push_back(num+4000);
        cnt[num+4000]++;
    }

    sort(v1.begin(), v1.end());

    double sum = 0;
    for(auto i : v1)
        sum += i;

    cout << (int)round(sum/n-4000) << endl;

    cout << v1[n/2]-4000 << endl;

    int minV = v1[0];
    int maxV = v1[v1.size()-1];
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    sort(v1.begin(), v1.end(), cmp);

	int most_cnt = 0;
    int most_num = 0;
	for (int i = 0; i < 8002; i++)
		if (most_cnt < cnt[i])
			most_cnt = cnt[i];

	int tmp = 0;
	for (int i = 0; i < 8002; i++)
	{
		if (cnt[i] == most_cnt)
		{
			most_num = i - 4000;
			tmp++;
		}
		if (tmp == 2)
			break;
	}
    cout << most_num << endl;
    cout << abs(maxV - minV) << endl;
}

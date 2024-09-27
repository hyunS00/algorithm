#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int LIMIT = 1000;

int n;
int u[LIMIT];
vector<int> sum;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> u[i];

    for(int i = 0; i < n-1; i++)
        for(int j = i ; j < n; j++)
            sum.push_back(u[i] + u[j]);

    sort(u, u + n);
    sort(sum.begin(), sum.end()); 

    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(binary_search(sum.begin(), sum.end(), u[i] - u[j])){
                cout << u[i] << endl;
                return 0;
            }
        }
    }
}
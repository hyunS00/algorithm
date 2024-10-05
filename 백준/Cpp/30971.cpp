#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N), C(N);
    for(auto &x:A) cin>>x;
    for(auto &x:B) cin>>x;
    for(auto &x:C) cin>>x;
    
    vector<int> perm(N);
    for(int i=0;i<N;i++) perm[i] = i;
    
    int max_umami = -1;
    
    do{
        bool valid = true;
        int current_umami = 0;
        for(int i=1;i<N;i++){
            // Check 눈치 조건
            if( (long long)C[perm[i-1]] * (long long)C[perm[i]] > K ){
                valid = false;
                break;
            }
            // 누적 감칠맛 계산
            current_umami += A[perm[i-1]] * B[perm[i]];
        }
        if(valid){
            max_umami = max(max_umami, current_umami);
        }
    } while(next_permutation(perm.begin(), perm.end()));
    
    cout << max_umami;
}

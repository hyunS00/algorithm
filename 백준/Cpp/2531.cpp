#include<iostream>
using namespace std;

int n, d, k, c;
int a[60010];
int f[3005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d >> k >> c;

    // 초밥 벨트 정보 입력 및 배열 확장
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    // 초기 윈도우 설정
    int kind = 0;
    for(int i = 0; i < k; i++) {
        if(f[a[i]]++ == 0) kind++;
    }

    // 초기 최대값 설정 (쿠폰 고려)
    int mx = kind;
    if(f[c] == 0) { // 쿠폰 초밥이 윈도우에 없을 경우
        mx = kind + 1;
    }

    // 슬라이딩 윈도우 이동
    for(int i = 1; i < n; i++){
        // 이전 윈도우의 첫 번째 초밥 제거
        if(--f[a[i-1]] == 0) kind--;
        
        // 새로운 초밥 추가
        if(f[a[i + k -1]]++ == 0) kind++;
        
        // 현재 윈도우의 초밥 종류 수 계산 (쿠폰 고려)
        if(f[c] == 0){
            mx = max(mx, kind + 1);
        }
        else{
            mx = max(mx, kind);
        }
    }

    cout << mx;
}

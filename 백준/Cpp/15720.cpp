#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

const int MAX = 1000;

int berger[MAX];
int side[MAX];
int drink[MAX];
int b, c, d;

bool comp(int a, int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> b >> c >> d;
    for(int i = 0; i < b; i++)
        cin >> berger[i];
    for(int i = 0; i < c; i++)
        cin >> side[i];
    for(int i = 0; i < d; i++)
        cin >> drink[i];

    sort(berger, berger+b, comp);
    sort(side, side+c, comp);
    sort(drink, drink+d, comp);

    int a = b;
    a = min(a, c);
    a = min(a, d);

    int setSum = 0;
    int sum = 0;
    for(int i = 0; i < a; i++)
        setSum += (berger[i] + side[i] + drink[i]);

    for(int i = a; i < b; i++)
        sum += berger[i];
    
    for(int i = a; i < c; i++)
        sum += side[i];

    for(int i = a; i < d; i++)
        sum += drink[i];

    int totalPrice = setSum + sum;
    int discountedPrice = (setSum * 9 + 5) / 10 + sum;  // 반올림을 포함한 정수 연산

    cout << totalPrice << endl;
    cout << discountedPrice << endl;
}
#include<iostream>
#define endl "\n"
using namespace std;

int n;
int heap[100005];
int hs = 0;
void push(int x){
    int cur = ++hs;
    heap[cur] = x;
    while(cur != 0 && heap[cur] < heap[cur/2]){
        swap(heap[cur], heap[cur/2]);
        cur /= 2;
    }
}

bool isEmpty(){
    return hs == 0;
}

int pop(){
    if(isEmpty()) return 0;

    int tmp = heap[1];
    heap[1] = heap[hs--];
    int parent = 1;
    while (parent*2 <= hs) {
        int child;
        if(parent*2+1 <= hs){
            if(heap[parent*2] < heap[parent*2+1]) child = parent*2;
            else child = parent*2+1;
        }
        else child = parent*2;

        if(heap[parent] > heap[child])
            swap(heap[parent],heap[child]);
        parent = child;
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if(x == 0) cout << pop() << endl;
        else push(x);
    }
}
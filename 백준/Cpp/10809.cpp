#include<iostream>
#include<vector>
using namespace std;

string sentence;
vector<int> alpha(26, -1);

int main(){
    cin >> sentence;

    for(int i = 0; i < sentence.length(); i++){
        int idx = (int)sentence[i]-97;
        if(alpha[idx] < 0)
            alpha[idx] = i;
    }

    for(int i : alpha){
        cout << i << " ";
    }
    cout << "\n";
}
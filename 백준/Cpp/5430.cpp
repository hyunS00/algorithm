#include<iostream>
#include<deque>
#define endl "\n"

using namespace std;

void parsing(deque<int> &dq, string arr);
void acProcess(deque<int> &dq, string p, int &rev, int &isError);
void printAns(deque<int>&dq, int &rev, int &isError);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;

    cin >> t;

    while (t--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> dq;

        parsing(dq, arr);

        int rev = 0;
        int isError = 0;
        
        acProcess(dq, p, rev, isError);
       
        printAns(dq, rev, isError);
    }
}

void parsing(deque<int> &dq, string arr){
    int num = 0;
    for(int i = 1; i+1 < (int)arr.size(); i++){
        if(arr[i] == ','){
            dq.push_back(num);
            num = 0;
        }else{
            num = num*10 + (arr[i]-'0');
        }
    }

    if(num) dq.push_back(num);
}

void acProcess(deque<int> &dq, string p, int &rev, int &isError){

    for(auto c : p){
        if(c == 'R') {
            rev = !rev;
        }
        else if(c == 'D'){
            if(dq.empty()){
                isError = 1;
                break;
            }
            else if(rev){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
        }
    }
}

void printAns(deque<int>&dq, int &rev, int &isError){
    if(isError){
            cout << "error" << endl;
    }
    else{
        cout << "[";
        if(!dq.empty()){
            if(rev){
                while (dq.size() > 1)
                {
                    int num = dq.back();
                    dq.pop_back();
                    cout << num << ",";
                }
                cout << dq.back();
            }
            else{
                while (dq.size() > 1)
                {
                    int num = dq.front();
                    dq.pop_front();
                    cout << num << ",";
                }
                cout << dq.front();
            }
        }
        cout << "]" << endl;
    }
}
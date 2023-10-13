#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin>>h>>w;
    bool board[h][w];

    for(int i = 0; i<h;i++){
        for(int j=0; j<w; j++){
            char wOrB;
            cin >> wOrB;
            board[i][j] = wOrB-66;
        }
    }

    int minCnt = 64;
    for(int i=0;i<=h-8;i++){
        for(int j=0; j<=w-8;j++){
            int drawCnt = 0;
            bool criteria = board[i][j];

            for(int k=i; k<i+8;k++){
                for(int l = j; l<j+8;l++){
                    if(criteria != board[k][l]) ++drawCnt;
                    criteria = !criteria;
                }
                criteria = !criteria;
            }
            if(minCnt>drawCnt) minCnt = drawCnt;

            drawCnt = 0;
            criteria = !board[i][j];
            for(int k=i; k<i+8;k++){
                for(int l = j; l<j+8;l++){
                    if(criteria != board[k][l]) ++drawCnt;
                    criteria = !criteria;
                }
                criteria = !criteria;
            }
            if(minCnt>drawCnt) minCnt = drawCnt;
        }
    }
    cout << minCnt << endl;
}
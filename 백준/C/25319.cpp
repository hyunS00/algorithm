#include <bits/stdc++.h>
using namespace std;

int N,M,S,C,L=0;

vector<queue<pair<int,int>>>  itemAddress(26);
int itemMap[50][50];

std::string replace_all(string &message, string &pattern, string &replace) {

    string result = message;
    string::size_type pos = 0;

    while ((pos = result.find(pattern)) != string::npos)
    {
        result.replace(pos, pattern.size(), replace);
    }

    return result;
}


void goTarget(int &xPos, int &yPos, int tXPos, int tYPos, string &command,string say){

    int xDif = 0;
    int yDif = 0;

    xDif = abs((xPos-tXPos));
    yDif = abs((yPos-tYPos));
    for(int i=0;i<xDif;i++){
        if(xPos > tXPos){
            command += "L";
            xPos--;
        }else if(xPos < tXPos){
            command += "R";
            xPos++;
        }
    }
    for(int i=0; i<yDif;i++){
        if(yPos > tYPos){
            command += "U";
            yPos--;
        }else if(yPos < tYPos){
            command += "D";
            yPos++;
        }
    }
    if(say !="ALL PERFECT"){
        command +="P";
    }
}

int main(){
    cin >> N >> M >> S;
    
    for(int i=0;i<N;i++){
        string item;
        cin >> item;
        for(int j=0;j<M;j++){
            pair<int,int> address;
            itemMap[i][j] = item[j]-'a';
            address.first = j;
            address.second = i;
            itemAddress[item[j]-'a'].push(address);
        }
    }

    string userID;
    cin >> userID;

    string say = "NOW PLAYING";
    string strL = "";

    int xPos = 0,yPos=0,tXPos=0,tYPos=0;
    while(say!="ALL PERFECT"){
        string command = "";
        for(int i=0;i<S && say != "ALL PERFECT";i++){
            if(itemAddress[userID[i]-'a'].empty()){
                string P = "P";
                string empty = "";
                command = replace_all(command,P,empty);
                C--;
                tXPos = M-1;
                tYPos = N-1;
                say = "ALL PERFECT";
            }else{
                pair<int,int> address;
                address =itemAddress[userID[i]-'a'].front();
                itemAddress[userID[i]-'a'].pop();
                tXPos = address.first;
                tYPos = address.second;
                
            }
            
            goTarget(xPos,yPos,tXPos,tYPos,command,say);
        }
        strL += command;
        C++;
    }
    L = strL.length();
    cout << C <<" "<< L <<endl;
    cout << strL << endl;
}
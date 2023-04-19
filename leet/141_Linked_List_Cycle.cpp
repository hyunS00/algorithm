#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    vector<int> valueVec;
    ListNode *tail;
    valueVec.push_back(head->val);
    tail = head->next;
    while((tail->next!=NULL)){
        if(find(valueVec.begin(),valueVec.end(),tail->val)==valueVec.end()){
            valueVec.push_back(tail->val);
            tail=tail->next;
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> value = {3,2,0,-4};
    int pos = 1;
    ListNode *linkedTailNode;
    ListNode *node;
    node->val=value[0];
    node->next=NULL;
    for(int i=1;i<value.size();i++){
        if(pos==i){
            linkedTailNode = node;
        }
        node=node->next;
    }
}
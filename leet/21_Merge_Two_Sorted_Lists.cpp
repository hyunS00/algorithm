#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list1Node;
        ListNode* list2Node;
        ListNode* bigNode;
        ListNode* smallNode;
        list1Node = list1;
        list2Node = list2;
        if(list1Node->val>list2Node->val){
            bigNode = list1Node;
            smallNode=list2Node;
        }else{
            bigNode = list2Node;
            smallNode=list1Node;
        }
        while (list1Node->next!=nullptr&&list2Node->next!=nullptr){
            while (smallNode->next!=nullptr||smallNode->val<bigNode->val){
                smallNode->next=smallNode;
            }
            if(smallNode->next!=nullptr){
                
            }
        }
        
    }
};

int mian(){

}

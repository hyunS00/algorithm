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
        ListNode *curr1;
        ListNode *curr2;
        ListNode *nextNode;
        curr1=list1;
        curr2=list2;
        if (curr1 == nullptr) {
            return curr2;
        }
        if (curr2 == nullptr) {
            return curr1;
        }
        ListNode *dummy = new ListNode();
        if(curr1->val>=curr2->val){        
            dummy->next=curr2;
        }else{
            dummy->next=curr1;
        }
        while(curr1->next!=nullptr&&curr2->next!=nullptr){
            if(curr1->val>=curr2->val){
                nextNode = curr2->next;
                if(nextNode==nullptr){
                    curr2->next=curr1;
                    break;
                }
                curr2->next=curr1;
                curr2=nextNode;
                
            }else{
                nextNode = curr1->next;
                if(nextNode==nullptr){
                    curr1->next=curr2;
                    break;
                }
                curr1->next=curr2;
                curr1=nextNode;
            }
        }
        return dummy->next;
    }
};

int mian(){

}

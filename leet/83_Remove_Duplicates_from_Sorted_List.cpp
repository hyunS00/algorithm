struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *curr;
        curr=dummy;
        while (curr->next!=nullptr){
            if(curr->val==curr->next->val){
                ListNode *deleteNode;
                deleteNode=curr->next;
                curr->next=deleteNode->next;
                delete(deleteNode);
            }
        }
        return dummy->next;
    }
};
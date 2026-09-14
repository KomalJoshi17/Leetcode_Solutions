/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;

        // move the fast ahead by n steps
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        
        // if fast is null, then remove head
        if(fast==nullptr) return head->next;

        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }

        // slow->next is the node to be removed
        ListNode* toDel=slow->next;
        slow->next=slow->next->next;
        delete toDel;

        return head;
    }
};
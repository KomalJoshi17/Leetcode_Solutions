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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* temp=head;
        ListNode* curr=temp->next;
        while(curr!=nullptr){
            if(temp->val==curr->val){
                temp->next=curr->next;
            }else{
                temp=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};
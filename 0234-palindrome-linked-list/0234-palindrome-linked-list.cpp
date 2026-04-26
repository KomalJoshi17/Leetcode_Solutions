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
    ListNode* reverseList(ListNode* slow) {
        ListNode* prev=NULL;
        ListNode* curr=slow;
        ListNode* next=NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        if(head==nullptr) return nullptr;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;

        ListNode* temp=middleNode(head);
        ListNode* rev=reverseList(temp);

        ListNode* normal=head;
        while(rev!=NULL){
            if(normal->val!=rev->val){
                return false;
            }
            normal=normal->next;
            rev=rev->next;
        }

        return true;
    }
};
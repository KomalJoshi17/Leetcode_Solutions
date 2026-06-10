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
    ListNode* reverse(ListNode* head,int k){
        ListNode* curr=head;
        ListNode* next=nullptr;
        ListNode* prev=nullptr;

        int count=0;
        while(curr!=nullptr && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;

        int count=0;
        while(curr!=nullptr && count<k){
            curr=curr->next;
            count++;
        }
        
        if(count<k) return head;

        ListNode* newHead=reverse(head,k);
        head->next=reverseKGroup(curr,k);
        return newHead;
    }
};
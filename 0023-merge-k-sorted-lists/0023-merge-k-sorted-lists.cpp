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
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->val < right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);

        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        ListNode* temp=new ListNode(-1);
        ListNode* tempp=temp;
        for(int i=0;i<arr.size();i++){
            ListNode* list=arr[i];
            
            while(list){
                tempp->next=new ListNode(list->val);
                tempp=tempp->next;
                list=list->next;
            }
        }
        
        ListNode* ans=mergeSort(temp->next);
        return ans;
    }
};
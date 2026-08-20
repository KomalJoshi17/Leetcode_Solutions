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
    ListNode* reverse(ListNode* leftNode,ListNode* rightNode){
        ListNode* prev=NULL;
        ListNode* curr=leftNode;
        ListNode* stop=rightNode->next;
        ListNode* next=NULL;

        while(curr!=stop){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;

        ListNode* temp=head;
        ListNode* leftNode=NULL;
        ListNode* prevNode=NULL;
        int count1=0;
        while(temp!=NULL){
            count1++;
            if(count1==left-1){
                prevNode=temp;
            }
            if(count1==left){
                leftNode=temp;
            }
            temp=temp->next;
        }

        temp=head;

        ListNode* rightNode=NULL;
        int count2=0;
        while(temp!=NULL){
            count2++;
            if(count2==right){
                rightNode=temp;
                break;
            }
            temp=temp->next;
        }

        ListNode* newRight=rightNode->next;
        ListNode* newHead=reverse(leftNode, rightNode);
        if(prevNode!=NULL){
            prevNode->next=newHead;
        }else{
            head=newHead;
        }
        leftNode->next=newRight;
        return head;
    }
};
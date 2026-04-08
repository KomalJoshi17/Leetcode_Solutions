/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // i have to make cloned nodes and insert them right after the original nodes
        Node* curr=head;

        while(curr!=nullptr){
            Node* dummy=new Node(curr->val);
            dummy->next=curr->next;
            curr->next=dummy;
            curr=dummy->next;
        }

        // then we have to set the random pointers of the cloned nodes
        curr=head;
        while(curr!=nullptr){
            if(curr->random!=nullptr){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        
        // then restore the original list and segregate the cloned list
        Node* dummy=new Node(0);
        Node* tail=dummy;

        curr=head;
        while(curr!=nullptr){
            Node* copyNode=curr->next;
            curr->next=copyNode->next;

            tail->next=copyNode;
            tail=tail->next;

            curr=curr->next;
        }

        return dummy->next;
    }
};
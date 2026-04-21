class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

    Node* current = head;
    while (current) {
        if (current->child) {
            Node* temp=current->child;
            while (temp->next) {
                temp=temp->next;
            }
            temp->next=current->next;
            if (current->next) {
                current->next->prev = temp;
            }

            current->next = current->child;
            current->child->prev = current;
            current->child = nullptr;
        }
        current = current->next;
    }
    return head;
    }
};
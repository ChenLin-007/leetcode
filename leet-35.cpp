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
        if (!head) return nullptr;
        Node *dummy = head;
        Node *res = nullptr;
        while(head){
            Node *temp = head->next;
            Node *copy = new Node(head->val);
            head->next = copy;
            copy->next = temp;
            head = temp;
        }

        head = dummy;
        while(head) {
            Node *copy = head->next;
            copy->random = (head->random)? head->random->next : nullptr; 
            head = head->next->next;        
        }

        head = dummy;
        res = dummy->next;
        while (head) {
            Node *N = head->next;
            // don't change orginal chain
            head->next = head->next->next;
            N->next = (N->next) ? N->next->next : nullptr;
            head = head->next;
        }
        return res;
    }
};
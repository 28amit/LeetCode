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
        if(!head)
            return head;
        Node *curr=head, *dummy=NULL;
        while(curr){
            dummy=new Node(curr->val,curr->next,NULL);
            curr->next=dummy;
            curr=dummy->next;
        }
        curr=head;
        while(curr){
            dummy=curr->next;
            if(curr->random)
                dummy->random=curr->random->next;
            curr=dummy->next;
        }
        curr=head;
        dummy=head->next;
        Node *cp=NULL; 
        while(curr){
            cp=curr->next;
            curr->next=cp->next;
            curr=cp->next;
            if(curr){
                cp->next=curr->next;
            }
        }
        return dummy;;
    }
};
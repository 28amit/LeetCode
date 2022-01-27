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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode *slow=head,*fast=head,*prev=NULL,*tmp=NULL;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        while(slow){
            tmp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=tmp;
        }
        ListNode *start=head, *end=prev;
        while(end->next){
            tmp=start->next;
            start->next=end;
            start=tmp;
            prev=end->next;
            end->next=tmp;
            end=prev;
        }
        
    }
};
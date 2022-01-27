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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
            return head;
        ListNode *dummy=new ListNode(0), *prev=NULL, *curr=dummy;
        dummy->next=head;
        for(int i=0;i<left;i++){
            prev=curr;
            curr=curr->next;
        }
        ListNode *curr1=curr, *prev1=prev;
        for(int i=left;i<=right;i++){
            ListNode *forward=curr1->next;
            curr1->next=prev1;
            prev1=curr1;
            curr1=forward;
        }
        prev->next=prev1;
        curr->next=curr1;
        return dummy->next;
    }
};
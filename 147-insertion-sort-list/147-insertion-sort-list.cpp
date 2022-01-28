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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy=new ListNode(0);
        while(head){
            ListNode *tmp=dummy;
            ListNode *curr=head->next;
            while(tmp->next&&tmp->next->val<head->val){
                tmp=tmp->next;
            }
            head->next=tmp->next;
            tmp->next=head;
            head=curr;
        }
        return dummy->next;
    }
};
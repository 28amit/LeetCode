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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode *smallHead=new ListNode(0);
        ListNode *bigHead=new ListNode(0);
        ListNode *small=smallHead;
        ListNode *big=bigHead;
        while(head){
            if(head->val<x){
                small->next=head;
                small=small->next;
            }
            else{
                big->next=head;
                big=big->next;
            }
            head=head->next;
        }
        small->next=bigHead->next;
        big->next=NULL;
        return smallHead->next;
    }
};
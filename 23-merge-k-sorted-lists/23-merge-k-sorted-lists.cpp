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
    ListNode* merge(vector<ListNode*>& lists,int left,int right){
        if(left==right)
            return lists[left];
        int k=right-left+1;
        ListNode *h1=NULL,*h2=NULL;
        h1=merge(lists,left,left+k/2-1);
        h2=merge(lists,left+k/2,right);
        if(!h1&&!h2){
            return h1;
        }
        if(!h2)
            return h1;
        if(!h1)
            return h2;
        ListNode *head=new ListNode(0);
        ListNode *itr=head;
        while(h1&&h2){
            if(h1->val>h2->val){
                itr->next=h2;
                h2=h2->next;
            }
            else{
                itr->next=h1;
                h1=h1->next;
            }
            itr=itr->next;
        }
        while(h1){
            itr->next=h1;
            h1=h1->next;
            itr=itr->next;
        }
        while(h2){
            itr->next=h2;
            h2=h2->next;
            itr=itr->next;
        }
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        if(k==1)
            return lists[0];
        ListNode *h1=NULL,*h2=NULL;
        h1=merge(lists,0,k/2);
        if(k/2+1<k)
            h2=merge(lists,k/2+1,k-1);
        if(!h1&&!h2){
            return h1;
        }
        if(!h2)
            return h1;
        if(!h1)
            return h2;
        ListNode *head=new ListNode(0);
        ListNode *itr=head;
        while(h1&&h2){
            if(h1->val>h2->val){
                itr->next=h2;
                h2=h2->next;
            }
            else{
                itr->next=h1;
                h1=h1->next;
            }
            itr=itr->next;
        }
        while(h1){
            itr->next=h1;
            h1=h1->next;
            itr=itr->next;
        }
        while(h2){
            itr->next=h2;
            h2=h2->next;
            itr=itr->next;
        }
        return head->next;
    }
};
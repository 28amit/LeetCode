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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        ListNode *dummy=new ListNode(0);
        while(!s1.empty()||!s2.empty()){
            int x;
            if(!s1.empty()){
                x=s1.top();
                s1.pop();
            }
            else
                x=0;
            int y;
            if(!s2.empty()){
                y=s2.top();
                s2.pop();
            }
            else
                y=0;
            int sum=x+y+carry;
            carry=sum/10;
            sum%=10;
            ListNode *tmp=new ListNode(sum);
            tmp->next=dummy->next;
            dummy->next=tmp;
        }
        if(carry>0){
            ListNode *sc=new ListNode(carry);
            sc->next=dummy->next;
            dummy->next=sc; 
        }
        return dummy->next;
    }
};
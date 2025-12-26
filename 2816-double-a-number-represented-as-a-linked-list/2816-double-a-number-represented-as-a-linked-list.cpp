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
    ListNode* rev(ListNode *head){
        ListNode *prev=NULL;
        ListNode *ptr=head;
        while(ptr!=NULL){
            ListNode *temp=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=temp;
            
        }return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode *newhead=rev(head);
        ListNode *ptr=newhead;
        ListNode *prev=NULL;
        int r=0;
        while(ptr!=NULL){
            int data=ptr->val*2+r;
            ptr->val=data%10;
            r=data/10;
            prev=ptr;
            ptr=ptr->next;
        }
        if(r!=0){
            ListNode* extra=new ListNode(r);
            prev->next=extra;
        } 
        return rev(newhead);
    }
};
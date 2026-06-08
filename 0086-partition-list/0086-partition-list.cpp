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
        ListNode* sl=new ListNode(0,nullptr);
        ListNode* bl=new ListNode(0,nullptr);
        ListNode* s=sl;
        ListNode* b=bl;
        while(head!=NULL){
            if(head->val<x){
                s->next=head;
                s=s->next;
            }else{
                b->next=head;
                b=b->next;
            }head=head->next;
        }
        s->next=bl->next;
        b->next=NULL;
        ListNode* r=sl->next;
        delete sl;
        delete bl;
        return r;

    }
};
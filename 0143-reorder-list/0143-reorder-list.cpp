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
        if(head==NULL||head->next==NULL) return;
        ListNode* ptr=head;
        while(ptr->next->next!=nullptr){
           ptr=ptr->next;
        }
        ListNode* scdlast=ptr;
        ListNode* last=scdlast->next;
        scdlast->next=last->next;
        ListNode* temp=head->next;
        head->next=last;
        last->next=temp;
        reorderList(last->next);
    }
};
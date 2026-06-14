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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int maxval=0;
        while(fast && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* nextNode,*prev=nullptr;
        while(slow){
            nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        while(prev){
            maxval=max(maxval,head->val+prev->val);
            prev=prev->next;
            head=head->next;
        }return maxval;
    }
};
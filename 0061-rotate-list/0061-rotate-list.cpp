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
   ListNode* LastNode(ListNode* temp,int k){
        while (--k && temp) {
            temp = temp->next;
        }
        return temp;
   }
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==nullptr) return head;
      ListNode* tail=head;
      int cnt=1;
      while(tail->next!=nullptr){
        cnt++;
        tail=tail->next;
      }  
      if(k%cnt==0) return head;
      k=k%cnt;
      tail->next=head;
      ListNode* newNode=LastNode(head,cnt-k);
      head=newNode->next;
      newNode->next=nullptr;
      return head;
    }
};
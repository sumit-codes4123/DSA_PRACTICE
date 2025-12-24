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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      if(!head || !head->next || !head->next->next)return {-1,-1};
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nxt=head->next->next;
        int idx=1;
        vector<int>pos;
        while(nxt!=NULL){
            if((curr->val>prev->val&&curr->val>nxt->val)||(curr->val<prev->val&&curr->val<nxt->val)) pos.push_back(idx);
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
            idx++;
        }
        if(pos.size()<2)return {-1,-1};
        int mini=INT_MAX;
        int maxi=pos.back()-pos.front();
        for(int i=1;i<pos.size();i++){
            mini=min(mini,pos[i]-pos[i-1]);
        }
        return {mini,maxi};
    }
};
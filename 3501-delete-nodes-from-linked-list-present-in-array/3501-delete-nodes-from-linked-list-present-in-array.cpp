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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>ans{nums.begin(),nums.end()};
        ListNode* dum=new ListNode(0);
        dum->next=head;
        ListNode* prev=dum;
        ListNode* curr=head;
        while(curr!=nullptr){
            if(ans.find(curr->val)!=ans.end())  prev->next=curr->next;
            else prev=curr;
            curr=curr->next;
        }return dum->next;
    }
};
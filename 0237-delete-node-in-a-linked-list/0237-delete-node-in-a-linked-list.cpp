/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
          if (node == nullptr || node->next == nullptr) return;
        ListNode* nextNode = node->next;
        // Copy data from next node to current node
        node->val = nextNode->val;
        // Bypass the next node
        node->next = nextNode->next;
        // Free memory (optional in LeetCode, but good practice)
        delete nextNode;
    }
};
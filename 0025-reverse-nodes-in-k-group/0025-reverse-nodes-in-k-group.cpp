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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* getkthnode(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;

        while (temp != nullptr) {
            ListNode* kthnode = getkthnode(temp, k);
            if (kthnode == nullptr) {
                if (prevlast) prevlast->next = temp;
                break;
            }

            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;

            ListNode* newHead = reverseList(temp); // ✅ store result
            if (temp == head) head = newHead;
            else prevlast->next = newHead;

            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};

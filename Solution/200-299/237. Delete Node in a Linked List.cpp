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
        // record the next node
        ListNode* nodeNext = node->next;
        // copy the value
        node->val = nodeNext->val;
        node->next = nodeNext->next;
        // delete the next node
        delete nodeNext;
    }
};

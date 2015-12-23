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
    ListNode* deleteDuplicates(ListNode* head) {
        // special cases
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // record the head node
        ListNode* retNode = head;
        for (ListNode* curNode = head->next; curNode; ) {
            ListNode* curNext = curNode->next;
            // delete if value is equal
            if (curNode->val == head->val) {
                head->next = curNode->next;
                delete curNode;
            }
            else {
                head = head->next;
            }
            curNode = curNext;
        }
        // return the head node
        return retNode;
    }
};

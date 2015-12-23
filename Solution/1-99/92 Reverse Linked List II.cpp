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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // deal with special case
        if (head == NULL || m == n) {
            return head;
        }
        // init dummy node
        ListNode *befHead = new ListNode(0);
        befHead->next = head;
        head = befHead;
        // move m-2 step
        for (int i = m - 1; i > 0; --i) {
            head = head->next;
        }
        // record some info
        ListNode* befM = head;
        ListNode* curM = head->next;
        ListNode* aftN = NULL;
        head = head->next;
        // begin reverse
        for (int i = n - m; i >= 0; --i) {
            aftN = head->next;
            head->next = befM->next;
            befM->next = head;
            head = aftN;
        }
        curM->next = aftN;
        // return the result
        befM = befHead->next;
        delete befHead;
        return befM;
    }
};

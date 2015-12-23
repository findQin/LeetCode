/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // dummy node version 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode befHead = ListNode(0);
        for (ListNode* headNext; head != NULL; head = headNext) {
            headNext = head->next;
            head->next = befHead.next;
            befHead.next = head;
        }
        return befHead.next;
    }
};

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
    ListNode* reverseList(ListNode* head) {
        ListNode* ret = NULL;
        for (ListNode* headNext; head != NULL; head = headNext) {
            headNext = head->next;
            head->next = ret;
            ret = head;
        }
        return ret;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // get length of the linked list
    int getLength(ListNode* head) {
        int len = 0;
        for (; head; head = head->next) {
            len++;
        }
        return len;
    }
    // reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* ret = NULL;
        for (ListNode* headNext; head != NULL; head = headNext) {
            headNext = head->next;
            head->next = ret;
            ret = head;
        }
        return ret;
    }
public:
    void reorderList(ListNode* head) {
        int len = getLength(head);
        // special case
        if (len < 3) {
            return;
        }
        // split list into 2 part
        ListNode* l1 = head;
        ListNode* l2 = head;
        // reverse the second part
        for (int i = len / 2; i > 0; --i){
            l2 = l2->next;
        }
        // add end
        ListNode* l1Last = l2;
        l2 = l2->next;
        l1Last->next = NULL;
        l2 = reverseList(l2);
        // merge into one list
        while (l2) {
            ListNode* l1Next = l1->next;
            ListNode* l2Next = l2->next;
            l1->next = l2;
            l2->next = l1Next;
            l1 = l1Next;
            l2 = l2Next;
        }
    }
};

/**
 * Reverse a singly linked list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 * A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * 使用的是头插的方法
     *
     * */
    ListNode* reverseList(ListNode* head) {
        ListNode *h = nullptr;
        ListNode *n = nullptr;

        while (head) {
            n = head->next;
            head->next = h;
            h = head;
            head = n;
        }

        return h;
    }
};

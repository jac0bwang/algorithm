/*
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *     Input: 1->2->4, 1->3->4
 *     Output: 1->1->2->3->4->4
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *prev = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }

            prev = prev->next;
        }

        if (l1)
            prev->next = l1;
        if (l2)
            prev->next = l2;

		return dummy.next;
    }
};


int main() {
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;

    Solution solve;
    ListNode *head = solve.mergeTwoLists(&a, &d);

    while(head){
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}


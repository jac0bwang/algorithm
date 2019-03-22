// Source : https://leetcode.com/problems/reverse-linked-list-ii/
// Author : Jacob Wang
// Date   : 2019-03-22

/******************************************************************************
*
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
*
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
*
* return 1->4->3->2->5->NULL.
*
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
*
*
******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || m >= n)
			return head;

		ListNode dummy(0);
		dummy.next = head;
		int len = n - m + 1;

        ListNode *h = head;
        ListNode *prev_head = NULL;

        while (h && --m) {
            prev_head = h;
            h = h->next;
        }

        ListNode *list_tail = h;
        ListNode *new_head = NULL;
        ListNode *next = NULL;
        while (h && len) {
            next = h->next;
            h->next = new_head;
            new_head = h;
            h = next;
            len--;
        }

        list_tail->next = h;

        if (prev_head)
            prev_head->next = new_head;
        else
            dummy.next = new_head;

		return dummy.next;
    }
};

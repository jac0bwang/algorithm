/**
 * Source : https://leetcode.com/problems/merge-k-sorted-lists
 * Author : Jacob Wang
 * Date   : 2019-04-12
 */

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 *
 */

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
    /**
     * 1. 第一种办法是将 k 个链表按顺序合并 k - 1次， 时间复杂度为 O(k^2 * n)
     * 2. 第二种办法是将 k 个链表分治，两两进行合并
     * 这里使用第二种办法
     */
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *p = &head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1) {
            p->next = l1;
        }

        if (l2) {
            p->next = l2;
        }

        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }

        int mid = lists.size() / 2;

    	vector<ListNode*> sub1_lists;
    	vector<ListNode*> sub2_lists;

    	for (int i = 0; i < mid; i++){
	    	sub1_lists.push_back(lists[i]);
	    }

	    for (int i = mid; i < lists.size(); i++){
    		sub2_lists.push_back(lists[i]);
    	}

    	ListNode *l1 = mergeKLists(sub1_lists);
    	ListNode *l2 = mergeKLists(sub2_lists);

    	return mergeTwoLists(l1, l2);
    }
};


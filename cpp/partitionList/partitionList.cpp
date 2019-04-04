/**
 * Source : https://leetcode.com/problems/partition-list/
 * Author : Jacob Wang
 * Date   : 2019-04-04
 */

/**
 * Given a linked list and a value x, partition it such that all nodes less than
 * x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example:
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */

class Solution {
public:
    /**
     * 1. 使用 2 个临时头节点，分别是 大于等于 和 小于 给定值的节点
     * 2. 最后把 小于链表的尾指针，指向 大于等于 链表的开始
     * 3. 返回 小于链表 的头节点
     */
    ListNode* partition(ListNode* head, int x) {
    	ListNode less_head(0);
    	ListNode more_head(0);
    	ListNode *less_ptr = &less_head;
    	ListNode *more_ptr = &more_head;

        while(head) {
        	if (head->val < x) {
        		less_ptr->next = head;
        		less_ptr = head;
			} else {
				more_ptr->next = head;
				more_ptr = head;
			}
        	head = head->next;
        }

        less_ptr->next = more_head.next;
        more_ptr->next = NULL;

        return less_head.next;
    }
};

/**
 * Source : https://oj.leetcode.com/problems/linked-list-cycle-ii/
 * Author : Jacob Wang
 * Date   : 2019-04-04
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
     * 1. 遍历链表，将链表中节点的对应指针地址，插入 set
     * 2. 在遍历时插入节点前，需要在 set 中查找，第一个在set 中发现的节点地址
     *    就是链表环的起点
     */
    ListNode *detectCycle_1(ListNode *head) {
        std::set<ListNode *> node_set;
        while (head) {
            if (node_set.find(head) != node_set.end()) {
	        	return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return NULL;
    }

    /**
     * 1. 使用快慢指针
     * 2. 从 head and meet 出发， 两个指针速度一样，相遇就是环的起点
     */
    ListNode *detectCycle_2(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;

        ListNode *meet = NULL;
        while (fast) {
            slow = slow->next;
            fast = fast->next;

            if (!fast) {
                return false;
            }

            fast = fast->next;

            if (fast == slow) {
                meet = fast;
                break;
            }
        }

        if (meet == NULL)
            return NULL;

        while (head && meet) {
            if (head == meet) {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }

        return NULL;
    }
};

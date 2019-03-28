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
	/*
     * 1. 遍历链表 A， 将其中的节点对应的指针地址，插入 set
     * 2. 遍历链表 B， 将其中的节点对应的指针地址，在 set 中查找，发现在 set 中
     *    的第一个节点地址，就是两个链表的交点
     * */
    ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
        std::set<ListNode *> node_set;
        while (headA) {
            node_set.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (node_set.find(headB) != node_set.end)
                return headB;

            headB = headB->next;
        }

        return NULL;
    }

    /*
     * 1. 计算两个链表的长度，计算较长的链表多出的长度
     * 2. 将较长链表指针移动到较短链表指针对齐的位置
     * */
    ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);

        if (lenA < lenB)
            headB = forwardList(lenB - lenA, headB);
        else
            headA = forwardList(lenA - lenB, headA);

        while (headA && headB) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
private:
    inline int getListLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    inline ListNode *forwardList(int len, ListNode *head) {
        while (head && len) {
            len--;
            head = head->next;
        }
        return head;
    }
};



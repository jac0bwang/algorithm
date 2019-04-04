/**
 * Source : https://leetcode.com/problems/copy-list-with-random-pointer/
 * Author : Jacob Wang
 * Date   : 2019-04-04
 */

/**
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 *  Example 1:
 *
 *  Input:
 *  {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 *
 *  Explanation:
 *  Node 1's value is 1, both of its next and random pointer points to Node 2.
 *  Node 2's value is 2, its next pointer points to null and its random pointer
 *  points to itself.
 *
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:

    /**
     * 深度拷贝 构造一个完全新的链表，即使将原来链表毁坏，新链表也可以独立使用
     * 通过使用 STL map 标准库，创建一对映射，把节点的地址和序号对应起来，
     */
    Node* copyRandomList(Node* head) {
        std::map<Node *, int> node_map;
        std::vector <Node *> node_vec;
        Node *p = head;
        int i = 0;

        while (p) {
            node_vec.push_back(new Node(p->val, NULL, NULL));
            node_map[p] = i;
            p = p->next;
            i++;
        }

        node_vec.push_back(0);
        i = 0;
        p = head;

        while (p) {
            node_vec[i]->next = node_vec[i +1];
            if (p->random) {
                int id = node_map[p->random];
                node_vec[i]->random = node_vec[id];
            }
            p = p->next;
            i++;
        }

        return node_vec[0];
    }
};

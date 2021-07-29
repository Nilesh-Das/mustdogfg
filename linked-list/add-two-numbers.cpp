// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *root, *node;
        while(l1 or l2 or carry) {
            int v1 = 0, v2 = 0;
            if(l1) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                v2 = l2->val;
                l2 = l2->next;
            }
            carry = (v1 + v2 + carry) / 10;
            int val = (v1 + v2 + carry) % 10;
            if(node) {
                node->next = ListNode(val);
                node = node->next;
            } else {
                node = ListNode(val);
                root = node;
            }
        }
        return root;
    }
};
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummyHead(0);  dummyHead.next = head;
        ListNode* curr = head;   ListNode* prev = &dummyHead;
        while (curr && curr->next) {
            if (curr->next->val == curr->val) {
                int duplicateVal = curr->val;
                while (curr && curr->val == duplicateVal) {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummyHead.next;
    }
};


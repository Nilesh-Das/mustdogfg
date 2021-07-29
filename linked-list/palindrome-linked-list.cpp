// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* reverse(ListNode * head) {
        ListNode *prev, *curr, *nest;
        curr = head;
        prev = NULL;
        while(curr != NULL) {
            nest = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nest;
        }
        head = prev;
        return head;
    } 
    
    void print(ListNode* head) {
        while(head != NULL) {
            cout << head->val << ' ';
            head = head->next;
        }
        cout << '\n';
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = head, fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL) slow=slow->next;
        slow = reverse(slow);
        fast = head;
        while(slow != NULL) {
            if(slow->val != fast->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
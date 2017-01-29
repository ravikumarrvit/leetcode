/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define DEBUG 1

class Solution {
public:

    ListNode* reverse_list(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next;
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *first_half, *second_half, *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast)
            slow = slow->next;
        
        second_half = slow;
        second_half = reverse_list(second_half);
        first_half = head;
        
        while(second_half) {
            if (first_half->val != second_half->val)
                return false;
            second_half = second_half->next;
            first_half = first_half->next;
        }
        
        return true;
    }
};
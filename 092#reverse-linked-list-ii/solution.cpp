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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *start = head, *prev = NULL, *curr, *rotate_prev = NULL, *next, *res_list;
        int start_index = 0;
        
        if (!head || !head->next || n == m)
            return head;
        
        while(start_index < m - 1) {
            prev = start;
            start = start->next;
            start_index++;
        }
        
        start_index = 0;
        
        curr = start, rotate_prev = NULL;
        while (start_index < (n - m) + 1) {
            next = curr->next;
            curr->next = rotate_prev;
            rotate_prev = curr;
            curr = next;
            start_index++;
        }
        start->next = curr;
        
        (prev) ? (prev->next = rotate_prev) : (head = rotate_prev);
        
        return head;
    }
};
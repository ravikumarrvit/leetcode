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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node;
        
        if (!head) 
            return NULL;
        if (!head->next)
            return head;
        
        int val = head->val;
        node = head->next;
        
        if (node->val != val) {
            head->next = deleteDuplicates(node);
            return head;
        } else {
            while (node && node->val == val) 
                node = node->next;
            return deleteDuplicates(node);
        }
    }
};
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
        ListNode *temp_node;
        if (!head || !head->next)
            return head;
        
        temp_node = head;
        
        while(temp_node) {
            while (temp_node->next && temp_node->val == temp_node->next->val)
                temp_node->next = temp_node->next->next;
            temp_node = temp_node->next;
        }
        
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define DEBUG 0
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy_head = new ListNode(INT_MIN);
        ListNode *temp_node, *node_to_remove = NULL;
        
        if (!head || n == 0)
            return head;
        
        dummy_head->next = head;
        temp_node = dummy_head;
        
        while (temp_node) {
            if (n)
                --n;
            else if (!n && !node_to_remove)
                node_to_remove = dummy_head;
            else
                node_to_remove = node_to_remove->next;
            temp_node = temp_node->next;
        }
        
        node_to_remove->next = node_to_remove->next->next;
        
        return dummy_head->next;
    }
};
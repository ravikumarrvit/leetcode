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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *temp_node, *node_in_cycle;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        
        if (fast && fast->next && slow == fast)
            node_in_cycle = slow;
        else
            return NULL;
        
        temp_node = head;
        
        while(temp_node != node_in_cycle) {
            temp_node = temp_node->next;
            node_in_cycle = node_in_cycle->next;
        }
        
        return temp_node;
    }
};
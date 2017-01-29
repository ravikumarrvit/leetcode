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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy_node = new ListNode(INT_MIN), *left_partition, *iter_node = head;
        ListNode *right_partition, *next;
        
        if (!head || !head->next)
            return head;
            
        dummy_node->next = head;
        left_partition = dummy_node;
        
        while(iter_node) {
            next = iter_node->next;
            if (iter_node->val < x) {
                if (iter_node != left_partition->next) {
                    iter_node->next = left_partition->next;
                    right_partition->next = next;
                }
                left_partition->next = iter_node;
                left_partition = left_partition->next;
            } else {
                right_partition = iter_node;
            }
            iter_node = next;
        }
        
        return dummy_node->next;
    }
};
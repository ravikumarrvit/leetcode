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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *unsorted_list, *sorted_list, *prev_node, *temp_node;
        
        if (!head)
            return head;
        unsorted_list = head->next;
        head->next = NULL;
        
        while(unsorted_list) {
            temp_node = unsorted_list;
            unsorted_list = unsorted_list->next;
            temp_node->next = NULL;
            sorted_list = head;
            
            while(sorted_list && temp_node->val > sorted_list->val) {
                prev_node = sorted_list;
                sorted_list = sorted_list->next;
            }
            
            if (sorted_list == head) {
                temp_node->next = head;
                head = temp_node;
            } else if (!sorted_list) {
                prev_node->next = temp_node;
            } else {
                temp_node->next = prev_node->next;
                prev_node->next = temp_node;
            }
            
        }
        
        return head;
    }
};
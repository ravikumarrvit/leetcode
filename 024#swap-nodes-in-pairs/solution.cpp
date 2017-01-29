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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp_node, *res_head = NULL, *prev_node = NULL;
        while(head && head->next) {
            if (!res_head)
                res_head = head->next;
            if (prev_node)
                prev_node->next = head->next;
            temp_node = head->next->next;
            head->next->next = head;
            head->next = temp_node;
            prev_node = head;
            head = temp_node;
        }
        
        return (!res_head) ? head : res_head;
    }
};
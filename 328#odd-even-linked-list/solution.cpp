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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_node = head, *even_node, *even_node_start;
        
        if (!head || !head->next)
            return head;
        
        even_node = head->next;
        even_node_start = even_node;
        
        while(odd_node && odd_node->next && even_node && even_node->next) {
            odd_node->next = even_node->next;
            even_node->next = even_node->next->next;
            odd_node->next->next = even_node_start;
            odd_node = odd_node->next;
            even_node = even_node->next;
        }
        
        return head;
    }
};
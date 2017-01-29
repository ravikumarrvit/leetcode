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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tail_node = head, *node_to_rotate = NULL, *next_head;
        int length = 1;
        
        if (!head || !head->next)
            return head;
        
        while(tail_node->next) {
            length++;
            tail_node = tail_node->next;
        }
        
        tail_node->next = head; // circle the link

        if(k %= length) {
            for(auto i = 0; i < length - k; i++) 
                tail_node = tail_node->next;
        }
        
        head = tail_node->next; 
        tail_node->next = NULL;
        
        return head;
    }
};
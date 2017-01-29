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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp_node;
        
        if(!head)
            return head;
        
        temp_node = head;
        
        while(head && head->val == val)
            head = head->next;
        
        while(temp_node->next) {
            if (val == temp_node->next->val)
                temp_node->next = temp_node->next->next;
            else
                temp_node = temp_node->next;
        }
        
        return head;
    }
};
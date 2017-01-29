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

    ListNode* reverse_list(ListNode *&head, int k, ListNode *&next_head) {
        ListNode *prev = NULL, *next, *curr = head;
        int group_len = k;
        
        if (!head)
            return NULL;
        
        // IMPORTANT: Check if we have enough nodes to form a group of size k
        while(curr && group_len) {
            prev = curr;
            curr = curr->next;
            group_len--;
        }
        
        if (group_len) {
            next_head = curr;
            return head;
        }
        
        curr = head;
        prev = NULL;
        
        while(curr && k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        
        next_head = curr;
        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy_node = new ListNode(INT_MIN), *curr_group, *next_group, *next_head;
        
        if (!head)
            return head;
        
        curr_group = dummy_node;
        next_group = head;
        
        while(curr_group) {
            curr_group->next = reverse_list(next_group, k, next_head);
            if (curr_group->next == next_group && !next_head)
                break;
            curr_group = next_group;
            next_group = next_head;
        }
        
        return dummy_node->next;
    }
};
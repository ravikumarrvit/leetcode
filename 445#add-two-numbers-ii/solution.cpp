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

    int list_length(ListNode *list_head) {
        int len = 0;
        
        while(list_head) {
            len++;
            list_head = list_head->next;
        }
        
        return len;
    }

    void prepend_list(ListNode *&list_head, int len) {
        ListNode *temp_node;
        while(len--) {
            temp_node = new ListNode(0);
            temp_node->next = list_head;
            list_head = temp_node;
        }
    }

    ListNode* addTwoNumbersRecurse(ListNode *l1, ListNode *l2, int &carry) {
        ListNode *res_node, *temp_node;
        int sum;
        
        if (!l1 && !l2)
            return NULL;
        
        temp_node = addTwoNumbersRecurse(l1->next, l2->next, carry);
        
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        sum %= 10;
        
        res_node = new ListNode(sum);
        res_node->next = temp_node;
        
        return res_node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1, len2, carry = 0;
        ListNode *res_head, *temp_node;
        
        len1 = list_length(l1);
        len2 = list_length(l2);
        
        (len1 > len2) ? prepend_list(l2, len1 - len2) : prepend_list(l1, len2 - len1);
        
        res_head = addTwoNumbersRecurse(l1, l2, carry);
        
        if (carry) {
            temp_node = new ListNode(carry);
            temp_node->next = res_head;
            res_head = temp_node;
        }
        
        return res_head;    
    }
};
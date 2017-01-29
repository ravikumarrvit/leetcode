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

    ListNode* addTwoNumbersRecurse(ListNode* l1, ListNode* l2, int carry) {
        int num1, num2, sum;
        ListNode* node;
        
        if (!l1 && !l2 && !carry)
            return NULL;
        
        num1 = (l1) ? l1->val : 0;
        num2 = (l2) ? l2->val : 0;
        
        sum = num1 + num2 + carry;
        carry = sum / 10;
        sum %= 10;
        
        node = new ListNode(sum);
        node->next = addTwoNumbersRecurse(( (l1) ? l1->next : NULL), ( (l2) ? l2->next : NULL), carry);
        
        return node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        return addTwoNumbersRecurse(l1, l2, 0);
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define DEBUG 0

class Solution {
public:

    ListNode* get_list_mid(ListNode *&head) {
        ListNode *slow = head, *fast = head, *prev = NULL;
        
        if (!head)
            return NULL;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (prev)
            prev->next = NULL;
        
        return slow;
    }

    ListNode* merge(ListNode *list1, ListNode *list2) {
        ListNode *res_list;
        
        if (!list1)
            return list2;
        if (!list2)
            return list1;
            
        if (list1->val > list2->val) {
            list2->next = merge(list1, list2->next);
            res_list = list2;
        } else {
            list1->next = merge(list1->next, list2);
            res_list = list1;
        }
        
        return res_list;
    }

    ListNode* mergeSortList(ListNode *head) {
        ListNode *mid, *res1, *res2, *res_list, *temp;
        
        mid = get_list_mid(head);
        if (mid != head) {
            res1 = mergeSortList(head);
            if (mid)
                res2 = mergeSortList(mid);
            res_list = merge(res1, res2);
        } else {
            res_list = head;
        }
        
        return res_list;
    }

    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;
        
        head = mergeSortList(head);
        
        return head;
    }
};
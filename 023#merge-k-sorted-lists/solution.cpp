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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret_node;
        
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            ret_node = l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            ret_node = l2;
        }
        
        return ret_node;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res_list;
        
        if (!lists.size())
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        
        for (int i = 1; i < lists.size(); i++) {
            if (i == 1)
                res_list = lists[0];
            res_list = mergeTwoLists(res_list, lists[i]);
        }
        
        return res_list;
    }
};
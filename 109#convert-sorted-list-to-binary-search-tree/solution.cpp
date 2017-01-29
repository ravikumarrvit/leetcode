/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define DEBUG 1
 
class Solution {
public:

    ListNode* split_list_at_mid(ListNode *&head) {
        ListNode *slow = head, *fast = head, *prev = NULL;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (prev)
            prev->next = NULL;
        
        return slow;
    }

    TreeNode* sortedListToBSTRecurse(ListNode* head) {
        TreeNode *root;
        ListNode *mid;
        
        if (!head)
            return NULL;
        
        mid = split_list_at_mid(head);
        
        root = new TreeNode(mid->val);
        root->left = (head != mid) ? sortedListToBSTRecurse(head) : NULL;
        root->right = (head != mid) ? sortedListToBSTRecurse(mid->next) : NULL;
        
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        if (!head->next)
            return new TreeNode(head->val);
        
        return sortedListToBSTRecurse(head);
    }
};
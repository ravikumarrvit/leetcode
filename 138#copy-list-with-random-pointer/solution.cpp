/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *res_list = NULL, *res_iter = NULL, *iter_node = head, *new_node;
        unordered_map<RandomListNode*, RandomListNode*> random_map;
        
        if (!head)
            return head;
        
        while(iter_node) {
            new_node = new RandomListNode(iter_node->label);
            if (!res_iter) {
                res_iter = new_node;
                res_list = res_iter;
            } else {
                res_iter->next = new_node;
                res_iter = res_iter->next;
            }
            random_map[iter_node] = new_node;
            iter_node = iter_node->next;
        }
        
        iter_node = head;
        res_iter = res_list;
        while(iter_node) {
            res_iter->random = (iter_node->random) ? random_map[iter_node->random] : NULL;
            res_iter = res_iter->next;
            iter_node = iter_node->next;
        }
        
        return res_list;
    }
};
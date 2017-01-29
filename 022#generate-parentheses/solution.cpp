class Solution {
public:

    void generateParanthesisRecurse(int n, vector<string> &result, string result_elem, 
                                        stack<char> paran_stack, int num_op) {
        if (result_elem.length() == 2 * n && paran_stack.empty()) {
            result.push_back(result_elem);
            return;
        }
        else if (paran_stack.empty()) {
            result_elem.push_back('(');
            paran_stack.push('(');
            generateParanthesisRecurse(n, result, result_elem, paran_stack, num_op + 1);
        }
        else if (paran_stack.top() == '(') {
            result_elem.push_back(')');
            paran_stack.pop();
            generateParanthesisRecurse(n, result, result_elem, paran_stack, num_op);
            if (num_op < n) {
                result_elem = result_elem.substr(0, result_elem.length() - 1);
                result_elem.push_back('(');
                paran_stack.push('(');
                paran_stack.push('(');
                generateParanthesisRecurse(n, result, result_elem, paran_stack, num_op + 1);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string result_elem;
        stack<char> paran_stack;
        
        generateParanthesisRecurse(n, result, result_elem, paran_stack, 0);
        
        return result;
    }
};

class Solution {
public:

    bool is_palindrome(const string &str_to_check, int start, int end) {
        while (start < end) {
            if (str_to_check[start++] != str_to_check[end--])
                return false;
        }
        return true;
    }

    void backtrack_partition(vector<vector<string>> &result, vector<string> &result_element, 
                                string &s, int start_index) {
        if (start_index == s.size())
            result.push_back(result_element);
        else {
            for (int i = start_index; i < s.size(); i++) {
                if (is_palindrome(s, start_index, i)) {
                    result_element.push_back(s.substr(start_index, i + 1 - start_index));
                    backtrack_partition(result, result_element, s, i + 1);        
                    result_element.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> result_element;
        
        backtrack_partition(result, result_element, s, 0);
        
        return result;
    }
};
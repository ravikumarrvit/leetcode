#define DEBUG 1

class Solution {
public:

    string trim(string s) {
        int first_space_index = s.find_first_not_of(' '), last_space_index;
        if (first_space_index == string::npos)
            return "";
        last_space_index = s.find_last_not_of(' ');
        
        return s.substr(first_space_index, (last_space_index - first_space_index) + 1);
    }

    void reverseWords(string &s) {
        string token;
        stack<string> result_stack;
        int split_pos;
        
        s = trim(s);
        if (s.empty())
            return;
        
        if (DEBUG)
            cout << "s: " << s << endl;
        
        while((split_pos = s.find(' ')) != string::npos) {
            token = s.substr(0, split_pos);
            result_stack.push(token);
            s = s.substr(s.find(' '));
            s = trim(s);
        }
        
        if (!s.empty())
            result_stack.push(s);
        
        s.clear();
        
        while(!result_stack.empty()) {
            s.append(result_stack.top());
            result_stack.pop();
            if (!result_stack.empty())
                s.append(" ");
        }
    }
};
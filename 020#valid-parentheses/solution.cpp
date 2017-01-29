class Solution {
public:
    bool isValid(string s) {
        stack<char> paran_match;
        for (char c : s) {
            if (paran_match.empty())
                paran_match.push(c);
            else if (paran_match.top() == '(' && c == ')' || paran_match.top() == '{' && c == '}' ||
                        paran_match.top() == '[' && c == ']')
                paran_match.pop();
            else
                paran_match.push(c);
        }
        return paran_match.empty() ? true : false;
    }
};
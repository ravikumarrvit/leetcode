class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size() == 0)
            return result;
        result = strs[0];
        if (strs.size() == 1)
            return result;
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(result) != 0)
                result = result.substr(0, result.length() - 1);
        }
        
        return result;
    }
};
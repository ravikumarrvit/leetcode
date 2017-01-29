class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> index_map;
        string temp_str;
        int k = 0, empty_str_index = -1;
        
        for (string str : strs) {
            if (str.empty()) {
                if (empty_str_index == -1) {
                    result.resize(k + 1);
                    empty_str_index = k++;
                }
                result[empty_str_index].push_back(str);
                continue;
            }
            temp_str = str;
            sort(str.begin(), str.end());
            if (!index_map[str]) {
                result.resize(k + 1);
                result[k].push_back(temp_str);
                index_map[str] = ++k;
            }
            else
                result[index_map[str] - 1].push_back(temp_str);
        }
        
        return result;
    }
};
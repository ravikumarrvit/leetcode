class Solution {
public:

    void split_parts(string version, vector<int> &parts) {
        int split_pos, start_index = 0;
        string token;
        
        while((split_pos = version.find('.', start_index)) != string::npos) {
            token = version.substr(start_index, (split_pos - start_index) + 1);
            if (token != ".")
                parts.push_back(stoi(token));
            start_index = split_pos + 1;
        }
        if (!(token = version.substr(start_index)).empty())
            parts.push_back(stoi(token));
    }

    int compareVersion(string version1, string version2) {
        vector<int> parts1, parts2;
        int length, num1, num2;
        
        split_parts(version1, parts1);
        split_parts(version2, parts2);
        
        length = max(parts1.size(), parts2.size());
        
        for (int i = 0; i < length; i++) {
            num1 = (i < parts1.size()) ? parts1[i] : 0;
            num2 = (i < parts2.size()) ? parts2[i] : 0;
            
            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
        }
        
        return 0;
    }
};
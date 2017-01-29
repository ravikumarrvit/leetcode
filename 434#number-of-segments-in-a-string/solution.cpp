class Solution {
public:

    string trim(string s) {
        int first_non_space = s.find_first_not_of(' '), last_non_space;
        if (first_non_space == string::npos)
            return "";
        last_non_space = s.find_last_not_of(' ');
        
        return s.substr(first_non_space, (last_non_space - first_non_space) + 1);
    }

    int countSegments(string s) {
        int segments = 0;
        char prev;
        
        s = trim(s);
        
        if (s.empty())
            return 0;
        for (char c : s) {
            if (c == ' ' && prev != ' ')
                segments++;
            prev = c;
        }
        
        return segments + 1;
    }
};
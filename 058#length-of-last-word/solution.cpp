#define DEBUG 0

class Solution {
public:

    string trim(const string& str)
    {
        size_t first = str.find_first_not_of(' ');
        if (string::npos == first)
        {
            return "";
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    int lengthOfLastWord(string s) {
        int space_index;
        s = trim(s);
        if (DEBUG)
            cout << "s: " << s + "_end" << endl;
        if (s.empty())
            return 0;
        if ((space_index = s.rfind(" ")) != string::npos && space_index != s.length() - 1)
            return s.length() - (space_index + 1);
        else
            return s.length();
    }
};
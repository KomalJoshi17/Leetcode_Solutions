class Solution {
public:
    void backtrack(int index, string &digits, string &current, vector<string> &ans, vector<string> &mapping) {
        if (index == digits.size()) {
            if (!current.empty())
                ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            current.push_back(c);
            backtrack(index + 1, digits, current, ans, mapping);
            current.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> ans;
        string current;

        if (digits.empty()) return ans;

        backtrack(0, digits, current, ans, mapping);
        return ans;
    }
};
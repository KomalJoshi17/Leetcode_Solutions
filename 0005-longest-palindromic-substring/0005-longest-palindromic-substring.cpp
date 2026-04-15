class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // Check odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = left;
                }
                left--;
                right++;
            }

            // Check even length palindrome
            left = i; 
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
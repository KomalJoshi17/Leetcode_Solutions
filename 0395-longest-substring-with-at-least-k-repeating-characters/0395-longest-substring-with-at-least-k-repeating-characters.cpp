class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k) return 0;

        unordered_map<char, int> freq;
        for (char ch : s){
            freq[ch]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] < k) {
                int j = i + 1;

                while (j < s.size() && freq[s[j]] < k){
                    j++;
                }

                int leftAns = longestSubstring(s.substr(0, i), k);
                int rightAns = longestSubstring(s.substr(j), k);

                if (leftAns > rightAns) return leftAns;
                else return rightAns;
            }
        }
        return s.size();
    }
};
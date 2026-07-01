class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26);
        for(char i:s) freq[i-'a']++;
        for(char i:t) freq[i-'a']--;

        for(int i:freq){
            if(i!=0) return false;
        }

        return true;
    }
};
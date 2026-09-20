class Solution {
public:
    int lengthOfLastWord(string s) {
        int size=s.size()-1;

        while(size>=0 && s[size]==' '){
            size--;
        }
        int count=0;
        while(size>=0 && s[size]!=' '){
            count++;
            size--;
        }
        return count;
    }
};
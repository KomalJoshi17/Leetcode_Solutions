class Solution {
public:
    string minWindow(string s, string t) {
        if (t == " ") return "";

        vector<int> freq(256, 0), greq(256, 0);
        int distchar = 0;
        for (int i = 0; i < t.size(); i++) {
            if (freq[t[i]] == 0) distchar++;
            freq[t[i]]++;
        }

        int c = 0;
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {
            greq[s[i]]++;
            if (freq[s[i]] != 0 && greq[s[i]] == freq[s[i]]) c++;

            if (c == distchar) {
                end = i;
                break;
            }
        }

        if (c < distchar) return "";

        int anss = start;
        int ansr = end;
        int minm = end - start + 1;

        while (end < s.size()) {
            // Try shrinking from the start
            while (start <= end && (freq[s[start]] == 0 || greq[s[start]] > freq[s[start]])) {
                greq[s[start]]--;
                start++;
            }

            if (end - start + 1 < minm) {
                minm = end - start + 1;
                anss = start;
                ansr = end;
            }

            end++;
            if (end < s.size()) {
                greq[s[end]]++;
            }
        }

        return s.substr(anss, minm);
    }
};
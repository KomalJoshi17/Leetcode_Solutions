// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.size()!=t.size()) return false;

//         for(int i=0;i<s.size();i++){
//             char c1=s[i];
//             char c2=t[i];

//             for(int j=0;j<s.size();j++){
//                 if(s[j]==c1 && t[j]!=c2) return false;
//                 if(s[j]!=c1 && t[j]==c2) return false;
//             }
//         }
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if(s.size()!=t.size()) return false;

//         unordered_map<char,int>map1;
//         unordered_map<char,int>map2;

//         for(int i=0;i<s.size();i++){
//             if(map1.find(s[i])==map1.end()){
//                 map1[s[i]]=i;
//             }
//             if(map2.find(t[i])==map2.end()){
//                 map2[t[i]]=i;
//             }

//             if(map1[s[i]]!=map2[t[i]]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        int freqS[256] = {0};
        int freqT[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (freqS[c1] != freqT[c2]) return false;
            freqS[c1] = freqT[c2] = i + 1;
        }

        return true;
    }
};
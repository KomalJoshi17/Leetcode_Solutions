class Solution {
public:
    int dp[31][31][31];

    bool solve(string &s1, string &s2, int i1, int i2, int len){
        if(dp[i1][i2][len] != -1) return dp[i1][i2][len];

        if(s1.substr(i1, len) == s2.substr(i2, len))
            return dp[i1][i2][len] = true;

        vector<int> count(26,0);
        for(int i=0;i<len;i++){
            count[s1[i1+i]-'a']++;
            count[s2[i2+i]-'a']--;
        }

        for(int c:count)
            if(c!=0) return dp[i1][i2][len]=false;

        for(int k=1;k<len;k++){

            if(solve(s1,s2,i1,i2,k) &&
               solve(s1,s2,i1+k,i2+k,len-k))
                return dp[i1][i2][len]=true;

            if(solve(s1,s2,i1,i2+len-k,k) &&
               solve(s1,s2,i1+k,i2,len-k))
                return dp[i1][i2][len]=true;
        }

        return dp[i1][i2][len]=false;
    }

    bool isScramble(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0,s1.length());
    }
};
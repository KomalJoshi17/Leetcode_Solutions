class Solution {
    vector<vector<int>> dp;
    int helper(string& s, string& t, int i, int j){
        if(i == s.size() and j == t.size()){
            return 1;
        }
        if(i >= s.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }


        int not_take = helper(s, t, i+1, j);
        int take = 0;
        if(s[i] == t[j]){
            take = helper(s, t, i+1, j+1);
        }

        return dp[i][j] = take + not_take;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return helper(s, t, 0, 0);
    }
};



/*
TC: O(S + 2^T)

int helper(string& s, string& t, int i, int j){
    if(i == s.size() and j == t.size()){
        return 1;
    }
    if(i >= s.size()){
        return 0;
    }


    int not_take = helper(s, t, i+1, j);
    int take = 0;
    if(s[i] == t[j]){
        take = helper(s, t, i+1, j+1);
    }

    return take + not_take;
}

int numDistinct(string s, string t) {
    return helper(s, t, 0, 0);
}

*/
class Solution {
public:
int n;
int dp[1005][3][101];
    int dfs(int day,int buy,int remain,vector<int>& prices){
        if(remain == 0 || day == n)return 0;
        if(dp[day][buy][remain] != -1)return dp[day][buy][remain];
        if(buy){
            int buying = -prices[day] + dfs(day+1 ,0,remain,prices);
            int nobuy = dfs(day+1 ,1 ,remain , prices);
            return dp[day][buy][remain] = max(buying,nobuy);
        }
        else {
            int sell = prices[day] + dfs(day+1, 1 , remain-1,prices);
            int nosell = dfs(day+1 , 0 , remain,prices);
            return dp[day][buy][remain] = max(sell , nosell);
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,k,prices);
    }
};
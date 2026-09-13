static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0], sold = 0, cool = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            int nh = max(hold, cool - prices[i]);
            int ns = hold + prices[i];
            int nc = max(cool, sold);
            hold = nh; sold = ns; cool = nc;
        }
        return max(sold, cool);
    }
};
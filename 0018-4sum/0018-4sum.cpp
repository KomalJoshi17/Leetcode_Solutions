class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 1; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                long long sum = (long long)target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                
                while (l < r) {
                    long long twoSum = nums[l] + nums[r];
                    if (twoSum < sum) {
                        l++;
                    } else if (twoSum > sum) {
                        r--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int x = nums[l], y = nums[r];
                        while (l < r && nums[l] == x) l++;
                        while (l < r && nums[r] == y) r--;
                    }
                }
            }
        }
        return ans;
    }
};
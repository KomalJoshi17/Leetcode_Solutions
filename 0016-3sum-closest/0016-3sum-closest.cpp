
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int p1 = i + 1, p2 = n - 1;

            while (p1 < p2) {
                int currSum = nums[i] + nums[p1] + nums[p2];
                if (abs(target - currSum) < abs(target - closestSum)) {
                    closestSum = currSum;
                }
                if (currSum < target) {
                    p1++;
                } else if (currSum > target) {
                    p2--;
                } else {
                    return target; 
                }
            }
        }
        return closestSum;
    }
};
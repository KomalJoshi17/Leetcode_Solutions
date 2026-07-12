class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx, vector<int>& candidates, int target) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // Move to next index (cannot reuse)
            solve(i + 1, candidates, target - candidates[i]);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target);

        return ans;
    }
};
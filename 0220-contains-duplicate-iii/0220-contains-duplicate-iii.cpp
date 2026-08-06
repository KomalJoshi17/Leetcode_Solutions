class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> st;

        for (int i = 0; i < nums.size(); i++) {
            auto it = st.lower_bound((long long)nums[i] - valueDiff);

            if (it != st.end() && *it <= (long long)nums[i] + valueDiff)
                return true;

            st.insert(nums[i]);

            if (st.size() > indexDiff)
                st.erase(st.find(nums[i - indexDiff]));
        }

        return false;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen;
        
        // Insert only positive numbers into the set
        for (int num : nums) {
            if (num > 0) {
                seen.insert(num);
            }
        }

        // Start checking from 1 upwards
        int missing = 1;
        while (seen.count(missing)) {
            missing++;
        }

        return missing;
    }
};
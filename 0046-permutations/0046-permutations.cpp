class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
    }
};class Solution {
public:
    void findPermutation(vector<int>& nums, set<vector<int>>&ans, int i){
        
        if(i>=nums.size()){
            ans.insert(nums);
            return;
        }    
       
        for(int j=i; j<nums.size(); j++){
          
            swap(nums[i], nums[j]);
       
            findPermutation(nums, ans, i+1);
            // Backtracking - to recreate the original input string
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> ans;
        int i=0;
        findPermutation(nums, ans, 0);
        vector<vector<int>> res;
        for(auto it: ans) res.push_back(it);
        return res;
    }
};
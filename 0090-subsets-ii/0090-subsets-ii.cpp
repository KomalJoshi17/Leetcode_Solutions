class Solution {
public:
    void subsetRec(vector<int>&nums, vector<int>&subset, vector<vector<int>>&res,int index){
        res.push_back(subset);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            } 

            subset.push_back(nums[i]);
            subsetRec(nums,subset,res,i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>subset;
        subsetRec(nums,subset,res,0);
        return res;
    }
};
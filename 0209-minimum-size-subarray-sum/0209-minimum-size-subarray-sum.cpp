class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int i=0;
        int j=0;
        int minLen=INT_MAX;

        while(j<nums.size()){
            sum+=nums[j];

            while(sum>=target){
                minLen=min(j-i+1,minLen);
                sum-=nums[i];
                i++;
            }
            j++;
        }

        return minLen==INT_MAX ? 0 : minLen;
    }
};
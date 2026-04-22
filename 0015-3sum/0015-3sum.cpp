class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int target=0;
        int n=arr.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            
            int req=target-arr[i];
            if(i>0 && arr[i]==arr[i-1]) continue;
            while(left < right){
                int sum=arr[left]+arr[right];

                if(sum==req){
                    ans.push_back({arr[i], arr[left], arr[right]});
                    while(left<right && arr[left]==arr[left+1]) left++;
                    while(left<right && arr[right]==arr[right-1]) right--;
                    left++;
                    right--;
                }else if(sum<req){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};
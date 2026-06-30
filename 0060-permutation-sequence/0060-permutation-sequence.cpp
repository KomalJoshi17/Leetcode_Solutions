class Solution {
public:
    string ans="";
    string curr="";
    int count=0;

    void solve(int n,int k,vector<bool>&used){
        if(curr.size()==n){
            count++;
            if(count==k){
                ans=curr;
            }
            return;
        }

        for(int i=1;i<=n;i++){
            if(used[i]) continue;
        
            used[i]=true;
            curr.push_back(i+'0');

            solve(n,k,used);
            curr.pop_back();

            used[i]=false;
        }
    }

    string getPermutation(int n, int k) {
        vector<bool>used(n+1,false);
        solve(n,k,used);
        return ans;    
    }
};
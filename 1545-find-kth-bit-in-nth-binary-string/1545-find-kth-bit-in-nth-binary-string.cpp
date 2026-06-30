class Solution {
public:
    char helper(int n,int k){
        if(n==1) return '0';
        int len=(1<<n)-1;
        int mid=(len+1)/2;

        if(mid==k) return '1';
        if(mid>k){
            return helper(n-1,k);
        }else{
            int kth=len-k+1;
            return helper(n-1,kth)=='0' ? '1':'0';
        }
    }

    char findKthBit(int n, int k) {
        return helper(n,k);
    }
};
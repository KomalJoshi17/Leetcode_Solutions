// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int res=1;
//         for(int i=left;i<=right;i++){
//             res&=i;
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         long long res=1;
//         for(long long i=left;i<=right;i++){
//             res&=i;
//         }
//         return (int)res;
//     }
// };


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right){
            right=right&(right-1);
        }
        return right;
    }
};
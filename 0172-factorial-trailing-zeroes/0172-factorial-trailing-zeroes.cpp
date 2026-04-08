class Solution {
public:
    int trailingZeroes(int n) {
//         int prod=1;
//         for(int i=n;i>0;i--){
//             prod*=i;
//         }
//         int count=0;
//         while (prod % 10 == 0 && prod > 0) {
//         count++;
//         prod /= 10;
//     }
//     return count;
//     }
// };
    int count = 0;
        while (n > 0) {
            n /= 5; // Count multiples of 5
            count += n; // Add how many multiples of 5 there are
        }
        return count;
    }
};
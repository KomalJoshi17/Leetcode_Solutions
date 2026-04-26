// class Solution {
// public:
//     double myPow(double x, int n) {
//         double ans = 1;
//         long long N = n; // Use long long to handle INT_MIN

//         if (N < 0) {
//             for (long long i = 1; i <= -N; i++) {
//                 ans *= 1 / x;
//             }
//         } else {
//             for (long long i = 1; i <= N; i++) {
//                 ans *= x;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // Handle INT_MIN
        double ans = 1;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }

        return ans;
    }
};
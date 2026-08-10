class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the overflow edge case explicitly
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the final quotient
        bool isPositive = (dividend < 0) == (divisor < 0);

        // Convert both inputs to negative to prevent overflow during absolute
        // value conversion (INT_MIN converted to positive overflow a 32-bit
        // signed int)
        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        long long quotient = 0;

        // Shift and subtract strategy
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Double the divisor until it exceeds the remaining dividend
            while ((tempDivisor << 1) <= absDividend) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest shifted divisor chunk and add the count
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // Apply the pre-calculated sign to the result
        return isPositive ? quotient : -quotient;
    }
};

class Solution {
public:
    double myPow(double a, int b) {
        if (b == 0) return 1; // Any number to the power of 0 is 1
        if (b < 0) {
            a = 1 / a; // Handle negative exponent
            if (b == INT_MIN) { 
                // Special case to avoid overflow when negating INT_MIN
                return a * myPow(a, INT_MAX);
            }
            b = -b;
        }

        double res = 1;
        while (b) {
            if (b & 1) res *= a; // Multiply result when the current bit is 1
            a *= a;              // Square the base
            b >>= 1;             // Right shift to process the next bit
        }
        return res;
    }
};

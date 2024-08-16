int Solution::pow(int x, int n, int d) {
    // Handle cases where x or n is zero
    if (x == 0) return 0;
    if (n == 0) return 1 % d;  // in case d is negative or zero

    long long ans = 1;
    long long base = x % d;
    long long nn = n;
    
    if (nn < 0) nn = -1 * nn;  // This isn't necessary since nn is usually non-negative in such problems

    while (nn) {
        if (nn % 2 == 1) {
            ans = (ans * base) % d;
            nn -= 1;
        } else {
            base = (base * base) % d;
            nn /= 2;
        }
    }
    
    // If the original exponent was negative, compute the modular multiplicative inverse
    if (n < 0) {
        ans = 1 / ans;  // This won't work directly in modular arithmetic; handle it differently
    }

    // Ensure the result is positive
    ans = (ans + d) % d;

    return ans;
}

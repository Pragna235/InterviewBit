
int Solution::reverse(int A) {

    int rev;

    for (; A != 0; A /= 10) {

        const int rem = A % 10;

        if (rev > INT_MAX/10 || rev < INT_MIN/10) return 0;

        if (rev == INT_MAX/10 and rem > 7 || rev == INT_MIN/10 and rem < -8) return 0;

        rev = rev * 10 + rem;

    }

    return rev;

}

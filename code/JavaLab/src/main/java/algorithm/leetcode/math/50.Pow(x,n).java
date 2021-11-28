package algorithm.leetcode.math;

/**
 * https://leetcode-cn.com/problems/powx-n/
 * <p>
 * 快速幂
 */
class LC50 {

    public double myPow(double x, int n) {

        long num = n;
        if (num == 0) {
            return 1;
        }

        boolean isF = false;
        if (n < 0) {
            isF = true;
            num *= -1;
        }

        double base = x;
        double other = 1;
        while (num > 1) {

            if (num % 2 == 1) {
                other *= base;
            }
            base = base * base;
            num /= 2;
        }
        base *= other;

        if (isF) {

            return 1.0 / base;

        } else {
            return base;
        }
    }
}
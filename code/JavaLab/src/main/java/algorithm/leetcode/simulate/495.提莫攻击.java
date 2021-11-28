package algorithm.leetcode.simulate;

/**
 * https://leetcode-cn.com/problems/teemo-attacking/
 */
class LC495 {


    public int findPoisonedDuration(int[] timeSeries, int duration) {

        int res = 0;

        for (int i = 0; i < timeSeries.length; i++) {

            if (i == timeSeries.length - 1) {
                res += duration;
            } else {
                int diff = timeSeries[i + 1] - timeSeries[i];
                res += Math.min(diff, duration);
            }
        }

        return res;
    }
}
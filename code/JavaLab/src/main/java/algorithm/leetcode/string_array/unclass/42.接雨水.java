package algorithm.leetcode.string_array.unclass;

/**
 * https://leetcode-cn.com/problems/trapping-rain-water/
 * <p>
 * 经典接雨水
 */
class LC42 {


    // 填平法
    public int trap(int[] height) {

        int sum = height[0];
        int maxIndex = 0;
        int maxVal = height[0];

        // 求最大值对应的下标
        for (int i = 1; i < height.length; i++) {
            sum += height[i];
            if (height[i] > maxVal) {
                maxIndex = i;
                maxVal = height[i];
            }
        }

        // 从左到右填平
        for (int i = 1; i < maxIndex; i++) {
            height[i] = Math.max(height[i], height[i - 1]);
        }

        // 从右到左填平
        for (int i = height.length - 2; i > maxIndex; i--) {
            height[i] = Math.max(height[i], height[i + 1]);
        }


        int newSum = 0;
        for (int i = 0; i < height.length; i++) {
            newSum += height[i];
        }

        return newSum - sum;
    }
}
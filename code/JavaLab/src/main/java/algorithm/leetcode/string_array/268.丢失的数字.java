package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/missing-number/
 */
class LC268 {


    // 边加边减
    public int missingNumber(int[] nums) {

        int sum = nums.length;
        for (int i = 0; i < nums.length; i++) {
            sum += i;
            sum -= nums[i];
        }
        return sum;
    }


    // 异或
    public int missingNumber1(int[] nums) {

        int sum = nums.length;
        for (int i = 0; i < nums.length; i++) {
            sum ^= i;
            sum ^= nums[i];
        }
        return sum;
    }
}
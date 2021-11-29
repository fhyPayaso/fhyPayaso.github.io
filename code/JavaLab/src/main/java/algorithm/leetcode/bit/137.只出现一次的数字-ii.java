package algorithm.leetcode.bit;


/**
 * https://leetcode-cn.com/problems/single-number-ii/submissions/
 * <p>
 * 给你一个整数数组nums ，除某个元素仅出现一次外，其余每个元素都恰出现三次 。请你找出并返回那个只出现了一次的元素。
 */
class LC137 {

    public static void main(String[] args) {
        LC137 main = new LC137();
        int[] nums = new int[]{-2, -2, 1, 1, 4, 1, 4, 4, -4, -2};
        System.out.println(main.singleNumber(nums));
    }

    // 这题和剑指offer数据集不一样, 可能存在负值

    public int singleNumber(int[] nums) {


        // 每个数字32位，按照二进制出现的次数进行累加

        int[] tab = new int[32];
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            for (int j = 0; j < 32; j++) {
                tab[j] += n & 1;
                n = n >> 1;
            }
        }

        // 出现三次的位置%3必然为0， 将为1的位置转化为10进制即可
        int res = 0;
        for (int j = 0; j < 32; j++) {
            res += (tab[j] % 3) << j;
        }
        return res;
    }


    // 设计电路思想, 时间复杂度On 空间复杂度O1
    public int singleNumber1(int[] nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            a = ~b & (a ^ num);
            b = ~a & (b ^ num);
        }
        return a;
    }
}
package algorithm.leetcode.bit;

/**
 * https://leetcode-cn.com/problems/single-number-ii/
 * <p>
 * 给你一个整数数组nums ，除某个元素仅出现一次外，其余每个元素都恰出现三次 。请你找出并返回那个只出现了一次的元素。
 */
class LC260 {

    public int[] singleNumber(int[] nums) {

        // 1. 第一步， 先对全体做异或，重复值被消掉，最终剩余为 a ^ b
        int flag = 0;
        for (int i = 0; i < nums.length; i++) {
            flag ^= nums[i];
        }

        // 2. 异或的性质为相反为1,相同为0 , 所以a^b中二进制为1的位，a,b的二进制对应项均相反， 以此可以进行分组
        // sum & (-sum) 获取最低位的1
        int f = flag & (-flag);

        // 3. 开始进行分组, f只有0和1两种情况 , 所以根据 i&fla g可以将nums分为两组，异或操作可以组内去重
        int res1 = 0, res2 = 0;
        for (int i = 0; i < nums.length; i++) {
            int t = nums[i] & f;
            if (t > 0) {
                res1 ^= nums[i];
            } else {
                res2 ^= nums[i];
            }
        }
        return new int[]{res1, res2};
    }
}
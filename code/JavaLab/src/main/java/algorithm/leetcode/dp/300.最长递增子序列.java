package algorithm.leetcode.dp;

/**
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 *
 * 经典dp
 */
class LC300 {

    public int lengthOfLIS(int[] nums) {

        int len = nums.length;
        int[] res = new int[len];

        res[0] = 1;
        int resVal = 1;
        for(int i = 1;i < len; i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[i] > nums[j] && res[j] >= res[i])
                    res[i] = res[j];
            }
            res[i]++;
            if(resVal < res[i])
                resVal = res[i];
        }
        return resVal;
    }
}
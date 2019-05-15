import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=347 lang=java
 *
 * [347] 前K个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (53.34%)
 * Total Accepted:    8.9K
 * Total Submissions: 16.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 说明：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 
 * 
 */
class Solution {
    public static List<Integer> topKFrequent(int[] nums, int k) {

        Integer flag = Integer.MAX_VALUE;
        List<Integer> resList = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        int maxNum = 0;
        for (int num : nums) {
            // 记录每个数字出现的频率
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
            // 记录出现的最大频率
            if (map.get(num) > maxNum)
                maxNum = map.get(num);
        }

        // 以频率为值进行桶排序，不同数字可能出现频率相同，所以用二维数组
        int[][] temp = new int[maxNum + 1][nums.length + 1];
        // 初始化二维数组
        for (int i = 0; i <= maxNum; i++) {
            // 只能对一维数组使用
            Arrays.fill(temp[i], flag);
        }
        for (int key : map.keySet()) {
            int value = map.get(key);
            // 该行未被填充过，首位设为key
            if (temp[value][0] == flag) {
                temp[value][0] = key;
            } else {
                // 否则将key放在末尾
                int j = 0;
                while (temp[value][j] != flag) {
                    j++;
                }
                temp[value][j] = key;
            }
        }
        // 倒序找前K个数
        for (int i = maxNum; i > 0; i--) {
            int j = 0;
            while (temp[i][j] != flag) {
                resList.add(temp[i][j]);
                if (resList.size() >= k) {
                    return resList;
                }
                j++;
            }
        }
        return resList;
    }
}

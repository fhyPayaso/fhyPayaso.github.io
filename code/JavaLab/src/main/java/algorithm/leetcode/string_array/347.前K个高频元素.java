package algorithm.leetcode.string_array;

import java.util.*;

/**
 * https://leetcode-cn.com/problems/top-k-frequent-elements/
 */
class LC347 {


    public static List<Integer> topKFrequent(int[] nums, int k) {

        int flag = 9999999;
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

        // 以频率为值进行桶排序
        int[][] temp = new int[maxNum + 1][nums.length + 1];

        for (int i = 0; i <= maxNum; i++) {
            Arrays.fill(temp[i], flag);
        }

        for (int key : map.keySet()) {
            int value = map.get(key);


            if (temp[value][0] == flag) {
                temp[value][0] = key;
            } else {
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
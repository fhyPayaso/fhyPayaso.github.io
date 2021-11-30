package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/subsets/description/
 * <p>
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * <p>
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 */
class LC78 {

    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {
        res.add(new ArrayList<>());
        LinkedList<Integer> list = new LinkedList<>();
        dfs(nums, nums.length, 0, list);
        return res;
    }

    public void dfs(int[] nums, int k, int step, LinkedList<Integer> list) {

        if (list.size() == k) {
            return;
        }

        for (int i = step; i < nums.length; i++) {
            list.add(nums[i]);
            res.add(new ArrayList<>(list));
            // 这里要从i开始才能去重
            dfs(nums, k, i + 1, list);
            list.removeLast();
        }
    }

}

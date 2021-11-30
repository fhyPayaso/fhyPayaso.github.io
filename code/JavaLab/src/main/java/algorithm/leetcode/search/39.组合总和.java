package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/combination-sum/description/
 * <p>
 * 给定一个无重复元素的正整数数组candidates和一个正整数target，找出candidates中所有可以使数字和为目标数target的唯一组合。
 * <p>
 * candidates中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。
 * <p>
 * 对于给定的输入，保证和为target 的唯一组合数少于 150 个。
 */
class LC39 {

    public static void main(String[] args) {

        LC39 mian = new LC39();


        int[] nums = new int[]{2, 3, 6, 7};
        mian.combinationSum(nums, 7);

    }


    public List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        Arrays.sort(candidates);
        LinkedList<Integer> list = new LinkedList<>();
        dfs(candidates, target, list, 0);
        return res;
    }

    public void dfs(int[] nums, int target, LinkedList<Integer> list, int start) {

        if (target < 0) {
            return;
        }

        if (0 == target) {
            res.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i < nums.length; i++) {
            list.add(nums[i]);
            dfs(nums, target - nums[i], list, i);
            list.removeLast();
        }
    }

}
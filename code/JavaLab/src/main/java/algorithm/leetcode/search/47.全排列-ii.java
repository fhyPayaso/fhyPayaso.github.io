package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/permutations-ii/description/
 * <p>
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 */
class LC47 {


    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> permuteUnique(int[] nums) {

        Arrays.sort(nums);
        boolean[] flag = new boolean[nums.length];
        LinkedList<Integer> list = new LinkedList<>();
        dfs(nums, flag, list);
        return res;
    }


    public void dfs(int[] nums, boolean[] flag, LinkedList<Integer> list) {

        if (list.size() == nums.length) {
            res.add(new ArrayList<>(list));
            return;
        }

        for (int i = 0; i < nums.length; i++) {

            if (i > 0 && (nums[i] == nums[i - 1]) && flag[i - 1]) {
                continue;
            }

            if (!flag[i]) {
                list.add(nums[i]);
                flag[i] = true;
                dfs(nums, flag, list);
                list.removeLast();
                flag[i] = false;
            }
        }
    }


}
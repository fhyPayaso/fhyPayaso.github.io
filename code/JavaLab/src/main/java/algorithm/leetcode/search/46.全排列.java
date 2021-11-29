package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/permutations/
 * <p>
 * 搜索全排列
 */
class LC46 {

    public List<List<Integer>> permute(int[] nums) {

        List<List<Integer>> res = new ArrayList<>();
        List<Integer> row = new ArrayList<>();

        boolean flags[] = new boolean[nums.length];
        dfs(res, row, nums, flags);
        return res;
    }

    public void dfs(List<List<Integer>> res, List<Integer> row, int[] nums, boolean[] flags) {

        if (row.size() == nums.length) {
            res.add(new ArrayList<>(row));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (!flags[i]) {
                flags[i] = true;
                row.add(nums[i]);
                dfs(res, row, nums, flags);
                row.remove(row.size() - 1);
                flags[i] = false;
            }
        }
    }
}
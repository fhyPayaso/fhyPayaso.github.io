package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/combinations/description/
 * <p>
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 */
class LC77 {

    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        LinkedList<Integer> row = new LinkedList<>();
        dfs(n, k, 1, row);
        return res;
    }


    public void dfs(int n, int k, int step, LinkedList<Integer> list) {

        if (list.size() == k) {
            res.add(new ArrayList<>(list));
            return;
        }

        for (int i = step; i <= n; i++) {
            list.add(i);
            // 这里要从i开始才能去重
            dfs(n, k, i + 1, list);
            list.removeLast();
        }
    }
}
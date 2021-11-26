package algorithm.leetcode.tree_50;

/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees/
 * <p>
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 */
class LC96 {


    public int numTrees(int n) {

        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1; // 一个节点只有一种情况


        for (int i = 2; i <= n; i++) {

            for (int j = 0; j < i; j++) {
                // 左子树种类情况
                int leftNum = dp[j];
                // 右子树种类情况(去掉根节点)
                int rightNum = dp[i - j - 1];
                // 左右子树情况做笛卡尔积即可
                dp[i] += leftNum * rightNum;
            }
        }
        return dp[n];
    }
}
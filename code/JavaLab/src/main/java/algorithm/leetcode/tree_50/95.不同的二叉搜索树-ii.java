package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 * <p>
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
 */
class LC95 {

    public List<TreeNode> generateTrees(int n) {
        return helper(1, n);
    }


    // 生成全部 节点范围在[left,right]的子树情况
    public List<TreeNode> helper(int left, int right) {

        List<TreeNode> res = new ArrayList<>();
        if (left > right) {
            res.add(null);
            return res;
        }

        for (int i = left; i <= right; i++) {
            // 分别生成左右子树的全部情况
            List<TreeNode> leftTree = helper(left, i - 1);
            List<TreeNode> rightTree = helper(i + 1, right);
            // 双重循环遍历所有情况(数组中节点代表每种情况的根节点)
            for (int j = 0; j < leftTree.size(); j++) {
                for (int k = 0; k < rightTree.size(); k++) {
                    TreeNode root = new TreeNode(i);
                    root.left = leftTree.get(j);
                    root.right = rightTree.get(k);
                    res.add(root);
                }
            }
        }
        return res;
    }
}
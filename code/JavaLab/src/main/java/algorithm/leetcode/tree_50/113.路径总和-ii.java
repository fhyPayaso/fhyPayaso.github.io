package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/path-sum-ii/
 * <p>
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径
 */
class LC113 {

    List<List<Integer>> res = new ArrayList();

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> list = new ArrayList();
        helper(root, targetSum, list);
        return res;
    }

    public void helper(TreeNode root, int targetSum, List<Integer> list) {

        if (root == null) {
            return;
        }
        targetSum -= root.val;
        list.add(root.val);
        if (root.left == null && root.right == null) {
            if (targetSum == 0) {
                List<Integer> row = new ArrayList(list);
                res.add(row);
            }
        }
        helper(root.left, targetSum, list);
        helper(root.right, targetSum, list);
        list.remove(list.size() - 1);
    }

}
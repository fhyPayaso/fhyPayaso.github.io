package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/binary-tree-paths/
 *
 * 给你一个二叉树的根节点 root ，按任意顺序 ，返回所有从根节点到叶子节点的路径。
 */
class LC257 {

    public List<String> binaryTreePaths(TreeNode root) {

        List<String> res = new ArrayList<>();
        helper(root, res, "");

        return res;
    }

    public void helper(TreeNode root, List<String> res, String str) {

        StringBuilder builder = new StringBuilder(str);

        if (root == null) {
            return;
        }

        builder.append(root.val);
        if (root.left == null && root.right == null) {
            res.add(builder.toString());
            return;
        }
        builder.append("->");
        helper(root.left, res, builder.toString());
        helper(root.right, res, builder.toString());
    }
}
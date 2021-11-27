package algorithm.offer.treeover;

import algorithm.config.TreeNode;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/12 9:38 下午
#   @Description   : 剑指 Offer 55 - II. 平衡二叉树
#  https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
# ====================================================*/
public class Offer55II {


    public boolean flag = true;

    public boolean isBalanced(TreeNode root) {

        if(root == null) {
            return true;
        }

        height(root);
        return flag;
    }

    public int height(TreeNode node) {
        if(node == null) {
            return 0;
        }
        int l = height(node.left);
        int r = height(node.right);
        if (Math.abs(l - r) > 1) {
            flag = false;
        }
        return Math.max(l, r) + 1;
    }

//    /**
//     * 暴力解法 nlgn
//     * @param root
//     * @return
//     */
//    public boolean isBalanced(TreeNode root) {
//
//        if (root == null) {
//            return true;
//        }
//
//        int l = height(root.left);
//        int r = height(root.right);
//        if (Math.abs(l - r) > 1) {
//            return false;
//        }
//        return isBalanced(root.left) && isBalanced(root.right);
//    }
//
//    public int height(TreeNode node) {
//
//        if (node == null)
//            return 0;
//        return Math.max(height(node.left), height(node.right)) + 1;
//    }

}

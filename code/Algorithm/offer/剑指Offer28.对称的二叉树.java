package algorithm.offer.easy;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.List;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/12 10:11 下午
#   @Description   : 剑指 Offer 28. 对称的二叉树
#   https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
# ====================================================*/
public class Offer28 {


    public boolean isSymmetric(TreeNode root) {
        if(root == null) {
            return true;
        }
        return helper(root.left, root.right);
    }

    public boolean helper(TreeNode n1, TreeNode n2) {

        if (n1 == null && n2 == null) {
            return true;
        }

        if (n1 == null || n2 == null) {
            return false;
        }

        if (n1.val != n2.val) {
            return false;
        }

        return helper(n1.left, n2.right) && helper(n1.right,n2.left);
    }


}

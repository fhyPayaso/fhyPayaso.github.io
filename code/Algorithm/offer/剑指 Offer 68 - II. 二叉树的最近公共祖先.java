package algorithm.offer.treeover;

import algorithm.config.TreeNode;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/11 3:20 下午
#   @Description   : 剑指 Offer 68 - II. 二叉树的最近公共祖先
#   https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
# ====================================================*/
public class Offer68II {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if (root == null) {
            return null;
        }
        if (root.val == p.val || root.val == q.val) {
            return root;
        }
        // 左子树中至少存在一个目标节点
        TreeNode leftRes = lowestCommonAncestor(root.left, p, q);
        // 右子树中至少存在一个目标节点
        TreeNode rightRes = lowestCommonAncestor(root.right, p, q);

        // 若两个点都不为空，说明当前节点即为祖先
        if (leftRes != null && rightRes != null) {
            return root;
        }
        // 若为空则说明都在另一个子树上
        return leftRes == null ? rightRes : leftRes;
    }


}

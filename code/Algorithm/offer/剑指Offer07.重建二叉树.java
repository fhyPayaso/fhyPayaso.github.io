package algorithm.offer.mid;

import algorithm.config.TreeNode;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/13 8:51 下午
#   @Description   : 剑指 Offer 07. 重建二叉树
#   https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
# ====================================================*/
public class Offer07 {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length - 1,
                inorder, 0, inorder.length - 1);
    }


    public TreeNode helper(int[] preorder, int l1, int r1,
                           int[] inorder, int l2, int r2) {

        if (r1 < l1 || r2 < l2) {
            return null;
        }

        // 前序遍历第一个值作为根节点
        int midVal = preorder[l1];
        TreeNode treeNode = new TreeNode(midVal);

        // 从中序遍历中找到分割点
        int index = 0;
        while (inorder[l2 + index] != midVal) {
            index++;
        }

        treeNode.left = helper(preorder, l1 + 1, l1 + index, inorder, l2, l2 + index - 1);
        treeNode.right = helper(preorder, l1 + index + 1, r1, inorder, l2 + index + 1, r2);


        return treeNode;
    }
}

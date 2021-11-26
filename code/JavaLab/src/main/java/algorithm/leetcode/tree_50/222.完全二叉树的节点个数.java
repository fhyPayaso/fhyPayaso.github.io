package algorithm.leetcode.tree_50;

import algorithm.config.TreeNode;

/**
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/
 * <p>
 * 注意不能用时间复杂度为O(n)的解法
 */
class LC222 {


    public int countNodes(TreeNode root) {

        if(root == null) {
            return 0;
        }

        int leftDeep = getDeep(root.left);
        int rightDeep = getDeep(root.right);

        if (leftDeep == rightDeep) {
            // 说明左子树一定是满二叉树
            return getNum(leftDeep) + 1 + countNodes(root.right);
        } else {
            // leftDeep > rightDeep 左子树不一定是满二叉树, 右子树一定是少一层的满二叉树
            return countNodes(root.left) + 1 + getNum(rightDeep);
        }
    }

    public int getNum(int deep) {
        return (int) (Math.pow(2, deep) - 1);
    }

    public int getDeep(TreeNode root) {

        int deep = 0;
        while (root != null) {
            root = root.left;
            deep++;
        }
        return deep;
    }


}